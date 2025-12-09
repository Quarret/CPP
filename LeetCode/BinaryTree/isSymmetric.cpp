#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool isSymmetric(TreeNode* root) {
    auto dfs = [&](this auto&& dfs, TreeNode* left, TreeNode* right) -> bool {
        if (!left && !right) return true;
        if (!left || !right) return false;

        return dfs(left->left, right->right) && dfs(left->right, right->left) && left->val == right->val;
    };
    
    return dfs(root->left, root->right);
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
