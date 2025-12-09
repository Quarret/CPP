#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<int> ans1, ans2;
void f(TreeNode* root, vector<int>& ans) {
    if (!root) return;

    if (!root->left && !root->right) {
        ans.push_back(root->val);
        return;
    }

    f(root->left, ans);
    f(root->right, ans);
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    f(root1, ans1);
    f(root2, ans2);

    return ans1 == ans2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
