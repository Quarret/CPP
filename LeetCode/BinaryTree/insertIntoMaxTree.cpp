#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (val > root->val) {
        TreeNode* dummy = new TreeNode(val, root, nullptr);
        return dummy;
    }

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root->right) {
            root->right = new TreeNode(val);
            return;
        }

        if (val > root->right->val) {
            root->right = new TreeNode(val, root->right, nullptr);
            return;
        }

        dfs(root->right);
    };

    dfs(root);
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
