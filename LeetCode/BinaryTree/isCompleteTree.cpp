#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int d = 0;
    
    while (!q.empty()) {
        int t = q.size(), cnt = 0;
        d++;
        bool left = 0, below = 0;

        for (int i = 0; i < t; i++) {
            auto node = q.front();
            q.pop();

            if (!node) {
                left = 1;
                continue;
            }
            if (left) {
                return false;
            }

            cnt++;
            if (node->left || node->right) {
                below = true;
            }
            q.push(node->left);
            q.push(node->right);
        }

        if (below && cnt < 1 << (d - 1)) {
            return false;
        } 
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
