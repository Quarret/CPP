#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool isBalanced(TreeNode* root, int depth = 0) {
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        int left = dfs(root->left);
        if (left == -1) {
            return -1;
        }
        int right = dfs(root->right);
        if (right == -1 || abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    };

    return dfs(root) != -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
