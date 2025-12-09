#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int sumEvenGrandparent(TreeNode* root) {
    int sum = 0;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root, int grandpa, int father) -> void {
        if (!root) return;

        if (!grandpa) sum += root->val;

        dfs(root->left, father % 2, root->val % 2);
        dfs(root->right, father % 2, root->val % 2);
    };

    dfs(root, 1, 1);
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
