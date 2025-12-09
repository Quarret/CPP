#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int kthSmallest(TreeNode* root, int k) {
    int idx = 0, ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        if (idx++ == k - 1) ans = root->val;
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
