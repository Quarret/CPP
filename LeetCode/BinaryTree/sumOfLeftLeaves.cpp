#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int ans = 0;
void f(TreeNode* root, int dir) {
    if (!root) return;
    if (!root->left && !root->right && dir == 0) {
        ans += root->val;
        return;
    }

    f(root->left, 0);
    f(root->right, 1);
}

int sumOfLeftLeaves(TreeNode* root) {
    f(root, 1);
    return ans;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    
    int res = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    auto left = root->left;
    if (left && !left->left && !left->right) {
        res += left->val;
    }

    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
