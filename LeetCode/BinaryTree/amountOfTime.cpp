#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

// 父节点 + 两次遍历
int amountOfTime(TreeNode* root, int start) {
    vector<TreeNode*> fa(100005, nullptr);
    TreeNode* start_node = nullptr;

    auto findFa = [&](this auto&& findFa, TreeNode* root, TreeNode* from) -> void {
        if (!root) {
            return;
        }

        fa[root->val] = from;
        if (root->val == start) {
            start_node = root;
        }

        findFa(root->left, root);
        findFa(root->right, root);
    };

    findFa(root, nullptr);

    auto dfs = [&](this auto&& dfs, TreeNode* root, TreeNode* from) -> int {
        if (!root) return -1;

        int res = -1;
        if (fa[root->val] != from) {
            res = max(res, dfs(fa[root->val], root));
        }

        if (root->left != from) {
            res = max(res, dfs(root->left, root));
        }

        if (root->right != from) {
            res = max(res, dfs(root->right, root));
        }

        return res + 1;
    };

    return dfs(start_node, start_node);
}

// 判断start是否在左右子树
int ans = 0, Start = 0;
pair<int, bool> dfs(TreeNode* root) {
    if (!root) return {0, false};

    auto [l_len, l_found] = dfs(root->left);
    auto [r_len, r_found] = dfs(root->right);

    if (root->val == Start) {
        ans = max(l_len, r_len);
        return {1, true};
    }

    if (l_found || r_found) {
        ans = max(ans, l_len + r_len);
        return {(l_found ? l_len : r_len), true};
    }
    return {max(l_len, r_len) + 1, false};
}

int amountOfTime(TreeNode* root, int start) {
    Start = start;
    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
