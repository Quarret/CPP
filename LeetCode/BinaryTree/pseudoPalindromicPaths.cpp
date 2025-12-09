#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int pseudoPalindromicPaths(TreeNode* root) {
    int res = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root, vector<int> path) -> void {
        if (!root) return;
        if (!root->left && !root->right) {
            path[root->val]++;

            int sum = 0;
            for (int i = 0; i <= 9; i++) {
                sum += path[i] % 2;
            }
            if (sum <= 1) res++;
            return;
        }

        path[root->val]++;
        dfs(root->left, path);
        dfs(root->right, path);
    };

    dfs(root, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    return res;
}

// 数组记录 异或优化
int pseudoPalindromicPaths(TreeNode* root) {
    int p[10]{};

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        p[root->val] ^= 1;
        int res = 0;
        if (!root->left && !root->right) {
            res = reduce(p, p + 10) <= 1;
        } else {
            res = dfs(root->left) + dfs(root->right);
        }

        // 还原, 避免当前节点记到其他路径中
        p[root->val] ^= 1;
        return res;
    };

    return dfs(root);
}

// 小于10位统计 + 模2 = 位运算 | ^
int pseudoPalindromicPaths(TreeNode* root, int mask = 0) {
    if (!root) return 0;

    mask ^= 1 << root->val;
    if (!root->left && !root->right) {
        return (mask & (mask - 1)) == 0;
    }

    return pseudoPalindromicPaths(root->left, mask) + pseudoPalindromicPaths(root->right, mask);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
