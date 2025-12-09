#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int maxAncestorDiff(TreeNode* root) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, int maxx, int minn) -> void {
        if (!root) return;

        ans = max({ans, abs(maxx - root->val), abs(minn - root->val)});
        maxx = max(maxx, root->val);
        minn = min(minn, root->val);

        dfs(root->left, maxx, minn);
        dfs(root->right, maxx, minn);
    };

    dfs(root, root->val, root->val);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
