#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* increasingBST(TreeNode* root) {
    TreeNode dummy(0);
    auto cur = &dummy;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        cur->right = new TreeNode(root->val, nullptr, cur->right);
        cur = cur->right;
        dfs(root->right);
    };

    dfs(root);
    return dummy.right;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
