#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    unordered_map<int, int> middle;
    for (int i = 0; i < n; i++) {
        middle[inorder[i]] = i;
    }

    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(preorder[l]);

        int mid = l + 1;
        while (mid <= r && middle[preorder[mid]] < middle[preorder[l]]) {
            mid++;
        }

        return new TreeNode(preorder[l], dfs(l + 1, mid - 1), dfs(mid, r));
    };

    return dfs(0, n - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}