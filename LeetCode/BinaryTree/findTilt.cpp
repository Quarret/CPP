#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int findTilt(TreeNode* root) {
    int ans = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        ans += abs(left - right);
        return left + right + root->val;
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
