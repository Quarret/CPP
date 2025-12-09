#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;


pair<int, TreeNode*> dfs(TreeNode* root) {
    if (!root) return {0, nullptr};

    auto [l_height, l_lca] = dfs(root->left);
    auto [r_height, r_lca] = dfs(root->right);
    if (l_height > r_height) {
        return {l_height + 1, l_lca};
    } else if (l_height < r_height) {
        return {r_height + 1, r_lca};
    }

    return {l_height + 1, root};
}
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return dfs(root).second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
