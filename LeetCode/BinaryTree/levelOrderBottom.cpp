#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr) return {};

    queue<TreeNode*> q;
    q.push(root);

    vector<vector<int>> ans;

    while (!q.empty()) {
        int t = q.size();
        vector<int> a;

        for (int k = 0; k < t; k++) {
            auto node = q.front();
            q.pop();
            a.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(a);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
