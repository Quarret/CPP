#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* pruneTree(TreeNode* root) {
    auto dfs = [&](this auto&& dfs, TreeNode *root) -> int {
        if (!root) return 0;

        int left = dfs(root->left);
        if (left == 0) root->left = nullptr;

        int right = dfs(root->right);
        if (right == 0) root->right = nullptr;

        int res = left + right + root->val;

        return res;
    };

    int ans = dfs(root);
    return ans ? root : nullptr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
