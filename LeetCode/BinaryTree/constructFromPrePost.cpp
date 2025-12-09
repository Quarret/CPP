#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    unordered_map<int, int> afer;
    for (int i = 0; i < n; i++) {
        afer[postorder[i]] = i;
    }

    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(preorder[l]);

        int mid = l + 1, pos = afer[preorder[mid]];
        while (mid <= r && afer[preorder[mid]] <= pos) {
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
