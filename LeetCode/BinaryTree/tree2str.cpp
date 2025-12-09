#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

string tree2str(TreeNode* root) {
    if (!root) {
        return "";
    }

    string s = to_string(root->val);

    if (!root->left && !root->right) return s;

    string left = "(" + tree2str(root->left) + ")";
    string right = root->right ? "(" + tree2str(root->right) + ")" : "";
    
    return s + left + right;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
