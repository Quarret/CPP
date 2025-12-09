#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;


TreeNode* dfs(vector<int>& nums, int l, int r) {
    if (l == r) return nullptr;

    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid], dfs(nums, l, mid), dfs(nums, mid + 1, r));
    return root;
    // return new TreeNode(nums[mid], dfs(nums, l, mid), dfs(nums, mid + 1, r));
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size());
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l + 1 >= r) return nullptr;

        int mid = l + (r - l) / 2;
        return new TreeNode(nums[mid], dfs(l, mid), dfs(mid, r));
    };

    return dfs(-1, nums.size()); 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
