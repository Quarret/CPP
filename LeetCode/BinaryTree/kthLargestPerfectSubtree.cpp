#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int kthLargestPerfectSubtree(TreeNode* root, int k) {
    vector<int> ans;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == -1 || right == -1 || left != right) {
            return -1;
        }

        int res = 1 + left + right;
        ans.push_back(res);
        return res;
    };

    dfs(root);
    sort(ans.begin(), ans.end(), greater());

    if (ans.size() < k) return -1;
    return ans[k - 1];
}

// 计数排序 完美二叉树的节点数 == (1 << h) - 1
int kthLargestPerfectSubtree(TreeNode* root, int k) {
    int cnt[10]{};
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) {
            // 叶节点高度为0, 充分利用数组
            return -1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == -2 || left != right) {
            return -2;
        }
        cnt[left + 1]++;
        return left + 1;;
    };

    dfs(root);

    for (int i = 9; i >= 0; i--) {
        int c = cnt[i];
        if (c >= k) {
            // 因为叶节点高度为0, h = i + 1
            return (1 << (i + 1)) - 1;
        } else {
            k -= c;
        }
    }
    // 完美二叉树的个数比k少
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
