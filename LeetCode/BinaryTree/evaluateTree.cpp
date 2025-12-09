#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool evaluateTree(TreeNode* root) {
    if (!root) return true;

    if (root->val < 2) {
        return root->val;
    } else if (root->val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    } else {
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
