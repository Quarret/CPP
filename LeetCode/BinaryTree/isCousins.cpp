#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

bool isCousins(TreeNode* root, int x, int y) {
    unordered_map<int, pair<int, TreeNode*>> mp;
    int d = 0;

    queue<pair<TreeNode*, TreeNode*>> q;
    q.emplace(root, nullptr);

    while (!q.empty()) {
        int t = q.size();
        d++;

        for (int i = 0; i < t; i++) {    
            auto [node, fa] = q.front();
            q.pop();

            mp[node->val] = {d, fa};
            if (node->left) q.emplace(node->left, node);
            if (node->right) q.emplace(node->right, node);
        }
    }

    cout << mp[x].second->val << ' ' << mp[y].second->val << '\n';
    return mp[x].first == mp[y].first && mp[x].second != mp[y].second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
