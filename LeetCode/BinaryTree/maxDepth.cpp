#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int maxDepth(TreeNode* root) {
    if (!root) return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
