#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int sumRootToLeaf(TreeNode* root) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, int path) -> void {
        if (!root) return;

        path = (path << 1) | root->val;
        if (!root->left && !root->right) {
            ans += path;
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    };

    dfs(root, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
