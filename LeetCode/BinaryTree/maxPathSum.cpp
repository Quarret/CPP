#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int maxPathSum(TreeNode* root) {
    int ans = -1e9;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        left = max(left, 0);
        right = max(right, 0);
        ans = max(ans, left + right + root->val);
        return max(max(left, right) + root->val, 0);
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
