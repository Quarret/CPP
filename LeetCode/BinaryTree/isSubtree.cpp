#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    auto dfs2 = [&](this auto&& dfs2, TreeNode* root1, TreeNode* root2) -> bool {
        if (!root1 || !root2) return root1 == root2;

        return dfs2(root1->left, root2->left) && dfs2(root1->right, root2->right) 
                && root1->val == root2->val;
    };

    auto dfs1 = [&](this auto&& dfs1, TreeNode* root) -> bool {
        if (!root) return false;

        if (root->val == subRoot->val && dfs2(root, subRoot)) {
            return true;
        }

        return dfs1(root->left) || dfs1(root->right);
    };

    return dfs1(root);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;

    auto isSameTree = [&](this auto&& isSameTree, TreeNode* root1, TreeNode* root2) -> bool {
        if (!root1 || !root2) return root1 == root2;

        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right) 
                && root1->val == root2->val;
    };

    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
