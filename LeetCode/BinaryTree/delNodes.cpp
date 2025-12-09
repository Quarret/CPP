#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_map<int, int> mp;
    for (int x : to_delete) {
        mp[x] = 1;
    }

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> TreeNode* {
        if (!root) return nullptr;

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (!mp[root->val]) {
            root->left = left;
            root->right = right;
            return root;
        } else {
            if (left) ans.push_back(left);
            if (right) ans.push_back(right);
            return nullptr;
        }
    };

    auto root1 = dfs(root);
    if (root1) ans.push_back(root1);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
