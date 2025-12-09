#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

// 先判断k - val, 在mp[val] = 1
bool findTarget(TreeNode* root, int k) {
    unordered_map<int, int> mp;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> bool {
        if (!root) return false;

        auto left = dfs(root->left);
        auto mid = mp[k - root->val];
        mp[root->val] = 1;
        return left || mid || dfs(root->right);
    };

    return dfs(root);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
