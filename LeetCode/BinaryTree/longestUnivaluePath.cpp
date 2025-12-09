#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int longestUnivaluePath(TreeNode* root) {
    int ans = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        left = !root->left || root->left->val != root->val ? 0 : left;
        right = !root->right || root->right->val != root->val ? 0 : right;

        ans = max(ans, left + right);
        return max(left, right) + 1;
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
