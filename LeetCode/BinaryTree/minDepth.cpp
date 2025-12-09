#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int minDepth(TreeNode* root) {
    int ans = 1e9;
    auto f = [&](this auto&& f, TreeNode* root, int depth) -> void {
        if (!root) return;

        if (root && !root->left && !root->right) {
            ans = min(ans, depth + 1);
            return;
        }
        
        depth++;
        f(root->left, depth);
        f(root->right, depth);
    };

    f(root, 0);

    if (!root) return 0;
    return ans;
}

int minDepth(TreeNode* root) {
    if (!root) return 0;

    if (!root->right) {
        return minDepth(root->left) + 1;
    }

    if (!root->left) {
        return minDepth(root->right) + 1;
    }

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
