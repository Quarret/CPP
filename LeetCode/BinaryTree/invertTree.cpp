#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    auto left = invertTree(root->left);
    auto right = invertTree(root->right);

    root->left = right;
    root->right = left;
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
