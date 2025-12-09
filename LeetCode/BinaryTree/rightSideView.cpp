#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    int h = 0;

    auto dfs = [&](this auto && dfs, TreeNode* root, int depth) -> void {
        if (!root) return;

        depth++;
        if (depth > h) ans.push_back(root->val);
        h = max(h, depth);

        dfs(root->right, depth);
        dfs(root->left, depth);
    };

    dfs(root, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
