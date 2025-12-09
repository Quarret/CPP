#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

void recoverTree(TreeNode* root) {
    TreeNode *node1 = nullptr, *node2 = nullptr, *pre = nullptr;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        if (pre && !node1 && root->val < pre->val) node1 = pre;
        if (pre && node1 && root->val < pre->val) node2 = root;

        pre = root;
        dfs(root->right);
    };

    dfs(root);
    swap(node1->val, node2->val);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
