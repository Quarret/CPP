#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> ans;
void f(TreeNode* root) {
    if (!root) return;

    f(root->left);
    f(root->right);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    f(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
