#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* trimBST(TreeNode* root, int low, int high) {
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> TreeNode* {
        if (!root) return nullptr;

        root->left = dfs(root->left);
        root->right = dfs(root->right);

        if (root->val < low || root->val > high) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            auto node = root->right;
            while (node->left) {
                node = node->left;
            }
            node->left = root->left;

            return root->right;
        }

        return root;
    };

    return dfs(root);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
