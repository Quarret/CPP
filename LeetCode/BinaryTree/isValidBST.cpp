#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

// 中序遍历: 递增数组
bool isValidBST(TreeNode* root) {
    long long pre = INT64_MIN;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> bool {
        if (!root) return true;

        if (!dfs(root->left)) return false;

        if (pre >= root->val) return false;
        pre = root->val;
        return dfs(root->right);
    };

    return dfs(root);
}

// 前序遍历: 从顶到底传递范围
bool isValidBST(TreeNode* root) {
    auto dfs = [&](this auto&& dfs, TreeNode* root, long long l, long long r) -> bool {
        if (!root) return true;

        int x = root->val;
        return l < x && x < r && dfs(root->left, l, x) && dfs(root->right, x, r);
    };

    return dfs(root, INT64_MIN, INT64_MAX);
}

// 后序遍历: 从底到顶传递范围
pair<long long, long long> dfs(TreeNode* root) {
    if (!root) return {INT64_MAX, INT64_MIN};

    auto [l_min, l_max] = dfs(root->left);
    auto [r_min, r_max] = dfs(root->right);
    if (root->val <= l_max || root->val >= r_min) {
        return {INT64_MIN, INT64_MAX};
    }

    long long x = root->val;
    return {min(l_min, x), max(x, r_max)};
}
bool isValidBST(TreeNode* root) {
    return dfs(root).second != INT64_MAX;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
