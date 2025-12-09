#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int maxProduct(TreeNode* root) {
    long long ans = 0, MOD = 1e9 + 7;
    auto sum = [&](this auto&& sum, TreeNode* root) -> long long {
        if (!root) return 0;

        return sum(root->left) + sum(root->right) + root->val;
    };

    long long total = sum(root);
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> long long {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long res = left + right + root->val;
        ans = max(ans, (total - res) * res);

        return res;
    };

    dfs(root);
    return ans % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
