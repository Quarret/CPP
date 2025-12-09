#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

int minimumOperations(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    
    int ans = 0;
    while (!q.empty()) {
        int t = q.size();
        vector<int> res(t, 0);
        
        for (int i = 0; i < t; i++) {
            auto node = q.front();
            q.pop();

            res[i] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        vector<int> sorted(res.begin(), res.end());
        sort(sorted.begin(), sorted.end());
        
        vector<int> vis(t, 0);
        for (int i = 0; i < t; i++) {
            res[i] = lower_bound(sorted.begin(), sorted.end(), res[i]) - sorted.begin();
        }

        for (int i = 0; i < t; i++) {
            if (vis[i]) continue;

            int x = res[i], c = 0;
            while (!vis[x]) {
                vis[x] = true;
                c++;
                x = res[x];
            }

            ans += c - 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
