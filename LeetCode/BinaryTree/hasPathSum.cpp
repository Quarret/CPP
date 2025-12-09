#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    if (root && !root->left && !root->right) {
        return targetSum == root->val;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum  - root->val);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
