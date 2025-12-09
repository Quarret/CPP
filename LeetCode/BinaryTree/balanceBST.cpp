#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    };

    dfs(root);

    auto f = [&](this auto&& f, int l, int r) -> TreeNode* {
        if (l + 1 >= r) {
            return nullptr;
        }

        int mid = l + (r - l) / 2;
        return new TreeNode(nums[mid], f(l, mid), f(mid, r));
    };

    int n = nums.size();
    return f(-1, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
