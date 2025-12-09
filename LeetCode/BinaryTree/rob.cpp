#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> memo;

    auto dfs = [&](this auto&& dfs, TreeNode* root, int canSteal) -> int {
        if (!root) return 0;

        auto it = memo.find(root);
        if (it != memo.end()) return it->second;

        int &res = memo[root];
        if (!canSteal) {
            res = dfs(root->left, 1) + dfs(root->right, 1);
        } else {
            res = max(dfs(root->left, 1) + dfs(root->right, 1), 
            dfs(root->left, 0) + dfs(root->right, 0) + root->val);
        }

        return res;
    };
    
    return dfs(root, 1);
}

// 选或不选 root
pair<int, int> dfs(TreeNode* root) {
    if (!root) return {0, 0};

    auto [l_rob, l_not_rob] = dfs(root->left);
    auto [r_rob, r_not_rob] = dfs(root->right);

    // 选 root
    int rob = l_not_rob + r_not_rob + root->val;

    // 不选 root
    int not_rob = max(l_rob, l_not_rob) + max(r_rob, r_not_rob);

    return {rob, not_rob};
}
int rob(TreeNode* root) {
    auto [rob, not_rob] = dfs(root);
    return max(rob, not_rob);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
