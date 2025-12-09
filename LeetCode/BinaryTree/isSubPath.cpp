#include <bits/stdc++.h>
#include "ListNode.h"
#include "TreeNode.h"
using i64 = long long;
using namespace std;

// 判断以当前 root 为链表开始节点是否合理
bool dfs(TreeNode* root, ListNode* head) {
    if (!head) return true;
    if (!root) return false;

    if (root->val != head->val) return false;
    return dfs(root->left, head->next) || dfs(root->right, head->next);
}

// 树中是否存在链表
bool isSubPath(ListNode* head, TreeNode* root) {
    if (!root) return false;

    // 以当前节点, 左孩子, 右孩子为根的树
    return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right); 
}


// 滚动哈希
bool isSubPath(ListNode* head, TreeNode* root) {
    // 将链表和随机为 hash 值
    // 随机 MOD 或 BASE
    const int MOD = 1'070'777'777;
    mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());
    const int BASE = uniform_int_distribution<>(8e8, 9e8)(rng);

    int n = 0;
    long long pow_base = 1;
    long long list_hash = 0;
    while (head) {
        n++;
        if (n > 1) {
            pow_base = pow_base * BASE % MOD;
        }
        list_hash = (list_hash * BASE + head->val) % MOD;
        head = head->next;
    }

    // 滚动数组
    vector<int> st;
    auto dfs = [&](this auto&& dfs, TreeNode* root, long long hash) -> bool {
        if (!root) {
            return false;
        }

        st.push_back(root->val);
        hash = (1LL * hash * BASE + root->val) % MOD;
        if (st.size() >= n) {
            if (hash == list_hash) {
                return true;
            }

            hash = ((hash - pow_base * st[st.size() - n]) % MOD + MOD) % MOD;
        }

        if (dfs(root->left, hash) || dfs(root->right, hash)) {
            return true;
        }

        // 还原
        st.pop_back();
        return false;
    };

    return dfs(root, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
