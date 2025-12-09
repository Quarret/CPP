#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> middle;
    for (int i = 0; i < n; i++) {
        middle[inorder[i]] = i;
    }
    
    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(postorder[r]);

        int mid = r - 1;
        while (mid >= l && middle[postorder[mid]] > middle[postorder[r]]) {
            mid--;
        }

        return new TreeNode(postorder[r], dfs(l, mid), dfs(mid + 1, r - 1));
    };

    return dfs(0, n - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
