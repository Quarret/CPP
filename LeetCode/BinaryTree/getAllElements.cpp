#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    priority_queue<int, vector<int>, greater<>> pq;

    int pre = -1e9;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        pq.push(root->val);
        pre = root->val;
        dfs(root->right);
    };

    dfs(root1);
    pre = -1e9;
    dfs(root2);

    vector<int> ans;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        ans.push_back(x);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
