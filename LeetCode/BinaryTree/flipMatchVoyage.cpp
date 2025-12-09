#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    int idx = 0;
    vector<int> ans;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> bool {
        // 子树根节点为空
        if (!root) {
            return true;
        }

        // 节点不匹配
        if (root->val != voyage[idx]) {
            return false;
        }

        idx++;
        // 左右匹配
        if (dfs(root->left) && dfs(root->right)) {
            return true;
        }

        // 左右不匹配, 交换
        if (dfs(root->right) && dfs(root->left)) {
            ans.push_back(root->val);
            return true;
        }

        // 交换后还不匹配
        return false;
    };

    if (dfs(root)) return ans;
    ans.clear();
    ans.push_back(-1);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
