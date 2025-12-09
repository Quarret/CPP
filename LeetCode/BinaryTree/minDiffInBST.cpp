#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int minDiffInBST(TreeNode* root) {
    int pre = INT_MIN / 2;
    int ans = INT_MAX;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        ans = min(ans, root->val - pre);
        pre = root->val;
        dfs(root->right);
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
