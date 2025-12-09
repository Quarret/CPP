#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 || !root2) return root1 == root2;
    
    if (root1->val != root2->val) return false;

    if (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) {
        return true;
    }

    if (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) {
        return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
