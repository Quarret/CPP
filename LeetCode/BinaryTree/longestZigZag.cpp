#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int longestZigZag(TreeNode* root) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, int dir, int d) {
        if (!root) return;

        ans = max(ans, d);

        if (dir == 0) {
            dfs(root->left, 0, 1);
            dfs(root->right, 1, d + 1);
        } else {
            dfs(root->left, 0, d + 1);
            dfs(root->right, 1, 1);
        }
    };

    dfs(root->left, 0, 1);
    dfs(root->right, 1, 1);
    return ans;
}


int longestZigZag(TreeNode* root) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, int l, int r) -> void {
        ans = max({ans, l, r});

        if (root->left) dfs(root->left, r + 1, 0);
        if (root->right) dfs(root->right, 0, l + 1);
    };

    dfs(root, 0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
