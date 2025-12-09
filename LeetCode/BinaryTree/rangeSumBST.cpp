#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int rangeSumBST(TreeNode* root, int low, int high) {
    int ans = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        if (root->val >= low && root->val <= high) ans += root->val;
        if (root->val >= low) dfs(root->left);
        if (root->val <= high) dfs(root->right);
    };

    dfs(root);
    return ans;
}

// 不要变动区间, 根据当前节点来判断
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    
    int x = root->val;
    int sum = x >= low && x <= high ? x : 0;
    if (x >= low) sum += rangeSumBST(root->left, low, high);
    if (x <= high) sum += rangeSumBST(root->right, low, high);

    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
