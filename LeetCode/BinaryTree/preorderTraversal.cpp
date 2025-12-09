#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> ans;
void f(TreeNode* root) {
    if (!root) return;

    ans.push_back(root->val);
    f(root->left);
    f(root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    f(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
