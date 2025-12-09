#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    TreeNode *ans = nullptr;
    int flag = 0;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root || flag) return;

        if (root->val == target->val) {
            ans = root;
            flag = 1;
            return;
        }

        dfs(root->left);
        dfs(root->right);
    };

    dfs(cloned);
    return ans;
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    // origin为空 cloned也为空
    if (!original || original == target) {
        return cloned;
    }

    auto left = getTargetCopy(original->left, cloned->left, target);
    if (left) return left;

    return getTargetCopy(original->right, cloned->right, target);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
