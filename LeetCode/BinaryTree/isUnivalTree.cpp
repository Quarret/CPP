#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool isUnivalTree(TreeNode* root) {
    int val = root->val;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> bool {
        if (!root) return true;

        return dfs(root->left) && dfs(root->right) && root->val == val;
    };

    return dfs(root);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
