#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) return 0;

        return dfs(root->left) + dfs(root->right) + 1;
    };

    TreeNode *dummy = nullptr;
    auto search = [&](this auto&& search, TreeNode* root) -> void {
        if (!root || dummy) {
            return;
        }

        if (root->val == x) {
            dummy = root;
            return;
        }

        search(root->left);
        search(root->right);
    };
    search(root);


    if (dummy == root) {
        int left = dfs(root->left);
        return left != n - 1 - left;
    } else {
        int left = dfs(dummy->left);
        int right = dfs(dummy->right);
        int s = n - (left + right + 1);
        return left > n - left -1 || right > n - right -1 || s > left + right;
    }
}

// 贪心
bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    int lsz = 0, rsz = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (x == root->val) {
            lsz = left;
            rsz = right;
        }

        return left + right + 1;
    };
    
    dfs(root);
    return max({lsz, rsz, n - 1 - lsz - rsz}) * 2 > n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
