#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int sumNumbers(TreeNode* root) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, int num) -> void {
        if (!root) return;
        if (root && !root->left && !root->right) {
            ans += root->val + num * 10;
            return;
        }

        dfs(root->left, num * 10 + root->val);
        dfs(root->right, num * 10 + root->val);
    };

    dfs(root, 0);
    return ans;
}

int sumNumbers(TreeNode* root, int x = 0) {
    if (!root) return 0;
    
    x = x * 10 + root->val;
    if (!root->left && !root->right) {
        return x;
    }

    return sumNumbers(root->left, x) + sumNumbers(root->right, x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
