#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (!root) return nullptr;

    auto left = removeLeafNodes(root->left, target);
    root->left = left;

    auto right = removeLeafNodes(root->right, target);
    root->right = right;

    if (!root->left && !root->right && root->val == target) return nullptr;
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
