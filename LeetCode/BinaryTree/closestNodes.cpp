#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<int> a;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        a.push_back(root->val);
        dfs(root->right);
    };

    dfs(root);

    int n = a.size();
    vector<vector<int>> ans;
    for (int x : queries) {
        int pos1 = upper_bound(a.begin(), a.end(), x) - a.begin();
        int pos2 = lower_bound(a.begin(), a.end(), x) - a.begin();
        
        int minn = pos1 == 0 ? -1 : a[pos1 - 1];
        int maxx = pos2 == n ? -1 : a[pos2];
        ans.push_back({minn, maxx}); 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
