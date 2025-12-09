#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;


TreeNode* bstFromPreorder(vector<int>& preorder) {
    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l > r) {
            return nullptr;
        }

        if (l == r) {
            return new TreeNode(preorder[l]);
        }

        // 以 root 为界分割左右
        int mid = l + 1;
        // 注意可以等于右界
        while (mid <= r && preorder[mid] < preorder[l]) {
            mid++;
        }
        TreeNode *res = new TreeNode(preorder[l], dfs(l + 1, mid - 1), dfs(mid, r));

        return res;
    };

    int n = preorder.size();
    return dfs(0, n - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
