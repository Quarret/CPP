#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

pair<int, TreeNode*> dfs(TreeNode* root, int path, int limit) {
    if (!root) {
        return {-1e9, nullptr};
    }

    auto [leftMax, left] = dfs(root->left, path + root->val, limit);
    auto [rightMax, right] = dfs(root->right, path + root->val, limit);

    // 由叶到root的最大路径
    int res = 0;
    if (!root->left && !root->right) {
        res = root->val;
    } else {
        res = max(leftMax, rightMax) + root->val;
    }
    root->left = left;
    root->right = right;
    return {res, res + path >= limit ? root : nullptr};
}

TreeNode* sufficientSubset(TreeNode* root, int limit) {
    return dfs(root, 0, limit).second;
}

// 到某一节点的路径只有一条
TreeNode* sufficientSubset(TreeNode* root, int limit) {
    limit -= root->val;
    if (!root->left && !root->right) {
        return limit > 0 ? nullptr : root;
    }

    if (root->left) root->left = sufficientSubset(root->left, limit);
    if (root->right) root->right = sufficientSubset(root->right, limit);

    return root->left || root->right ? root : nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
