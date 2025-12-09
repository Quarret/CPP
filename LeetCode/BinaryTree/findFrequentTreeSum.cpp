#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> mp;
    int maxx = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        int res = dfs(root->left) + dfs(root->right) + root->val;
        mp[res]++;
        maxx = max(maxx, mp[res]);
        return res;
    };

    dfs(root);
    vector<int> ans;
    for (auto [s, c] : mp) {
        if (c == maxx) ans.push_back(s);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
