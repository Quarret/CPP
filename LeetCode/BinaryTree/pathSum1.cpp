#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int pathSum(TreeNode* root, int targetSum) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, long long path) -> void {
        if (!root) return;

        path += 1LL * root->val;
        if (path == targetSum) ans++;

        dfs(root->left, path);
        dfs(root->right, path);
    };


    auto dfs1 = [&](this auto&& dfs1, TreeNode* root) -> void {
        if (!root) return;

        dfs(root, 0);

        dfs1(root->left);
        dfs1(root->right);
    };

    dfs1(root);
    return ans;
}

// 和之前正负数组中求区间和为0的子数组个数有异曲同工之妙
int pathSum(TreeNode* root, int targetSum) {
    int ans = 0;
    unordered_map<long long, int> cnt{{0, 1}};
    
    auto dfs = [&](this auto&& dfs, TreeNode* root, long long path) -> void {
        if (!root) return;

        path += root->val;
        ans += cnt[path - targetSum];

        cnt[path]++;
        dfs(root->left, path);
        dfs(root->right, path);
        cnt[path]--;
    };

    dfs(root, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
