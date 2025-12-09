#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

// 暴力出奇迹
int countPairs(TreeNode* root, int distance) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> vector<int> {
        if (!root) return {};
        if (!root->left && !root->right) return {0};

        vector<int> ret;
        auto left = dfs(root->left);
        for (auto &e : left) {
            if (++e > distance) continue;
            ret.push_back(e);
        }

        auto right = dfs(root->right);
        for (auto &e : right) {
            if (++e > distance) continue;
            ret.push_back(e);
        }

        for (int l : left) {
            for (int r : right) {
                ans += (l + r) <= distance;
            }
        }

        return ret;
    };

    dfs(root);
    return ans;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
