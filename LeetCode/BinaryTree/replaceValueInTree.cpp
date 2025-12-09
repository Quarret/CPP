#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* replaceValueInTree(TreeNode* root) {
    queue<pair<TreeNode*, TreeNode*>> q;
    q.emplace(root, nullptr);
    unordered_map<TreeNode*, int> mp;
    mp[nullptr] = root->val;
    int pre = root->val;

    while (!q.empty()) {
        int t = q.size(), s = 0;

        for (int i = 0; i < t; i++) {
            auto [node, fa] = q.front();
            q.pop();

            node->val = pre - mp[fa];
            if (node->left) {
                mp[node] += node->left->val;
                s += node->left->val;
                q.emplace(node->left, node);
            }

            if (node->right) {
                mp[node] += node->right->val;
                s += node->right->val;
                q.emplace(node->right, node);
            }
        }

        pre = s;
    }

    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
