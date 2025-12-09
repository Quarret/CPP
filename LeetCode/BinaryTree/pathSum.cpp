#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    int sum = targetSum;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        path.push_back(root->val);
        sum -= root->val;

        if (!root->left && !root->right && !sum) {
            ans.push_back(path);
        }

        dfs(root->left);
        dfs(root->right);

        path.pop_back();
        sum += root->val;
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
