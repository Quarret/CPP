#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

// max_element(left, right) 查找的是数组[left, right)范围内的
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l >= r) return nullptr;

        int mid = max_element(nums.begin() + l, nums.begin() + r) - nums.begin();
        return new TreeNode(nums[mid], dfs(l, mid), dfs(mid + 1, r));
    };

    return dfs(0, nums.size());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
