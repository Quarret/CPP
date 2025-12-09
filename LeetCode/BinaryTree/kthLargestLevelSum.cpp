#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

long long kthLargestLevelSum(TreeNode* root, int k) {
    vector<long long> ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int t = q.size();
        long long s = 0;

        for (int i = 0; i < t; i++) {
            auto node = q.front();
            q.pop();
            s += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(s);
    }

    if (ans.size() < k) return -1;

    sort(ans.begin(), ans.end(), greater());
    return ans[k - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
