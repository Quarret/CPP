#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

// 以 target 为根, 重新建树
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parents;
    auto dfs = [&](this auto&& dfs, TreeNode* root, TreeNode* fa) -> void {
        if (!root) return;

        parents[root] = fa;
        dfs(root->left, root);
        dfs(root->right, root);
    };
    dfs(root, nullptr);

    queue<TreeNode*> q;
    unordered_set<TreeNode*> vis;
    q.push(target);

    int d = 0;
    vector<int> ans;
    while (!q.empty()) {
        int t = q.size();

        for (int i = 0; i < t; i++) {
            auto node = q.front();
            q.pop();

            vis.insert(node);

            if (d == k) {
                ans.push_back(node->val);
            }

            if (node->left && !vis.contains(node->left)) q.push(node->left);
            if (node->right && !vis.contains(node->right)) q.push(node->right);
            if (parents[node] && !vis.contains(parents[node])) q.push(parents[node]);
        }

        d++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
