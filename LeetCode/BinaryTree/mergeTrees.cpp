#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return nullptr;

    auto left1 = root1 ? root1->left : nullptr;
    auto left2 = root2 ? root2->left : nullptr;
    auto right1 = root1 ? root1->right : nullptr;
    auto right2 = root2 ? root2->right : nullptr;

    auto left = mergeTrees(left1, left2);
    auto right = mergeTrees(right1, right2);

    int val1 = root1 ? root1->val : 0;
    int val2 = root2 ? root2->val : 0;
    TreeNode* root = new TreeNode(val1 + val2, left, right);
    return root;
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    // root1为空, 直接返回root2
    if (!root1) return root2;
    if (!root2) return root1;

    return new TreeNode(root1->val + root2->val, 
        mergeTrees(root1->left, root2->left), mergeTrees(root1->right, root2->right));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
