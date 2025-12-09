#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int ans = 1e9;
pair<int, int> dfs(TreeNode* root) {
    if (!root) return {1e9, -1e9};

    auto [l_min, l_max] = dfs(root->left);
    auto [r_min, r_max] = dfs(root->right);

    ans = min({ans, abs(root->val - l_max), abs(root->val - r_min)});

    return {min({l_min, r_min, root->val}), max({l_max, r_max, root->val})};
};
int getMinimumDifference(TreeNode* root) {
    dfs(root);
    return ans;  
}

// 中序遍历二叉搜索树, 得到的是递增数组
int getMinimumDifference(TreeNode* root) {
    int pre = INT_MIN / 2;
    int ans = INT_MAX;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        ans = min(ans, root->val - pre);
        pre = root->val;
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
