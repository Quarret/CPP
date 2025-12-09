#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
        return new TreeNode(val, root, nullptr);
    }

    auto dfs = [&](this auto&& dfs, TreeNode* root, int d) -> void {
        if (!root) return;
        if (d == depth - 1) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);  
            return;
        }

        d++;
        dfs(root->left, d);
        dfs(root->right, d);
    };

    dfs(root, 1);
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
