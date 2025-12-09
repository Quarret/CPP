#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* convertBST(TreeNode* root) {
    int bigger = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->right);
        bigger += root->val;
        root->val = bigger;

        dfs(root->left);
    };

    dfs(root);
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
