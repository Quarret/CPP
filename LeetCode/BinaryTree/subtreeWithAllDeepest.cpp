#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    auto maxDepth = [&](this auto&& maxDepth, TreeNode* root) -> int {
        if (!root) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    };
    int depth = maxDepth(root);

    TreeNode* ans = nullptr;
    int maxx = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root, int d) -> int {
        if (!root) return 0;

        int res = 0;
        if (!root->left && !root->right && d == depth - 1) {
            res = 1;
        } else {        
            d++;
            res = dfs(root->left, d) + dfs(root->right, d);
        }

        if (res > maxx) {
            ans = root;
            maxx = res;
        }
        return res;
    };

    dfs(root, 0);
    return ans;
}

// 一遍搜索 有递有归
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    TreeNode* ans = nullptr;
    int maxDepth = -1;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root, int d) -> int {
        if (!root) {
            maxDepth = max(maxDepth, d);
            return d;
        }
        
        int left_maxDepth = dfs(root->left, d + 1);
        int right_maxDepth = dfs(root->right, d + 1);
        if (left_maxDepth == right_maxDepth && left_maxDepth == maxDepth) {
            // 归的时候会自动保证最深深度的叶结点越来越多
            ans = root;
        }
        
        return max(left_maxDepth, right_maxDepth);
    };

    dfs(root, 0);
    return ans;
}

// lca
// return {height, lca}
pair<int, TreeNode*> dfs(TreeNode* root) {
    if (!root) {
        return {0, nullptr};
    }

    auto [left_height, left_lca] = dfs(root->left);
    auto [right_height, right_lca] = dfs(root->right);
    if (left_height > right_height) {
        return {left_height + 1, left_lca};
    } else if (left_height < right_height) {
        return {right_height + 1, right_lca};
    }

    return {left_height + 1, root};
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return dfs(root).second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
