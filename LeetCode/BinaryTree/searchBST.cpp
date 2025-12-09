#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return nullptr;

    if (root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
