#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

// choose by_fa, by_child
tuple<int, int, int> dfs(TreeNode* root) {
    if (!root) {
        return {INT32_MAX / 2, 0, 0};
    }

    auto [l_choose, l_by_fa, l_by_child] = dfs(root->left);
    auto [r_choose, r_by_fa, r_by_child] = dfs(root->right);

    // 当前 root 安装
    int choose = min({l_choose, l_by_fa, l_by_child}) + min({r_choose, r_by_fa, r_by_child}) + 1;
                    
    // by_fa
    int by_fa = min(l_choose, l_by_child) + min(r_choose, r_by_child);

    // by_child
    int by_child = min({l_choose + r_choose, l_by_child + r_choose, l_choose + r_by_child});

    return {choose, by_fa, by_child};
}
int minCameraCover(TreeNode* root) {
    auto [choose, _, by_child] = dfs(root);
    return min(choose, by_child);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
