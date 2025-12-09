#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        if (val < root->val) {
            if (root->left) dfs(root->left);
            else {
                root->left = new TreeNode(val);
                return;
            }
        } else {
            if (root->right) dfs(root->right);
            else {
                root->right = new TreeNode(val);
                return;
            }
        }
    };

    dfs(root);
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
