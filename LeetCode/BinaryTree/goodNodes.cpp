#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int goodNodes(TreeNode* root) {
    int ans = 0;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root, int maxx) -> void {
        if (!root) return;

        if (root->val >= maxx) ans++;
        maxx = max(maxx, root->val);
        dfs(root->left, maxx);
        dfs(root->right, maxx);
    };

    dfs(root, -1e9);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
