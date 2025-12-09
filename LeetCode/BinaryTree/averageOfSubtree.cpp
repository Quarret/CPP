#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int averageOfSubtree(TreeNode* root) {
    int ans = 0;

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int res = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        ans += res / cnt == root->val;
        return {res, cnt};
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
