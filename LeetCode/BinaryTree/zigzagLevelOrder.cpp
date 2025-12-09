#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};

    deque<TreeNode*> deq;
    deq.push_back(root);
    int even = 0;

    vector<vector<int>> ans;
    while (!deq.empty()) {
        int t = deq.size();
        vector<int> a;

        for (int k = 0; k < t; k++) {
            TreeNode* node = nullptr;
            if (!even) {
                node = deq.front();
                deq.pop_front();
                a.push_back(node->val);

                if (node->left) deq.push_back(node->left);
                if (node->right) deq.push_back(node->right);
            } else {
                node = deq.back();
                deq.pop_back();
                a.push_back(node->val);

                if (node->left) deq.push_front(node->left);
                if (node->right) deq.push_front(node->right);
            }
            cout << node->val << ' ';
        }
        cout << '\n';

        ans.push_back(a);
        even ^= 1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
