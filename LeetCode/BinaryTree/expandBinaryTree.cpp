#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* expandBinaryTree(TreeNode* root) {
    if (!root) return nullptr;
    
    auto left = expandBinaryTree(root->left);
    if (left) root->left = new TreeNode(-1, root->left, nullptr);

    auto right = expandBinaryTree(root->right);
    if (right) root->right = new TreeNode(-1, nullptr, root->right);

    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
