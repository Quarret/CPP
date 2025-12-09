#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int ans = 0;
tuple<int, int, int> dfs(TreeNode* root) {
    if (!root) return {INT32_MAX, INT32_MIN, 0};


    auto [l_min, l_max, l_res] = dfs(root->left);
    auto [r_min, r_max, r_res] = dfs(root->right);

    int x = root->val;
    if (x <= l_max || x >= r_min) {
        return {INT32_MIN, INT32_MAX, 0};
    }

    int res = l_res + x + r_res;
    ans = max(ans, res);
    return {min(l_min, x), max(r_max, x), res};
};

int maxSumBST(TreeNode* root) {
    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
