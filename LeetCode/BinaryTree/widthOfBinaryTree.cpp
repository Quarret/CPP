#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

int widthOfBinaryTree(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int t = q.size();
        bool ok = false;

        int l = -1, r = -1;
        for (int i = 0; i < t; i++) {
            auto node = q.front();
            q.pop();

            if (node && l < 0) l = i;
            if (node) {
                r = i;
                ok = true;
            }

            if (node) {
                q.push(node->left);
                q.push(node->right);
            } else {
                q.push(nullptr);
                q.push(nullptr);
            }
        }

        if (!ok) break;
        ans = max(r - l + 1, ans);
    }

    return ans;
}

// 打标记 
int widthOfBinaryTree(TreeNode* root) {
    unsigned ans = 0;
    queue<pair<TreeNode*, unsigned>> q;
    q.emplace(root, 1);

    while (!q.empty()) {
        int t = q.size();

        unsigned l = UINT_MAX, r = 0;

        for (int i = 0; i < t; i++) {
            auto [node, idx] = q.front();
            q.pop();

            l = min(l, idx);
            r = max(r, idx);

            if (node->left) {
                q.emplace(node->left, 2 * idx);
            }

            if (node->right) {
                q.emplace(node->right, 2 * idx + 1);
            }
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
