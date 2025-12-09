#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;


int ans = 0;
unordered_map<int, int> mp;

void f(TreeNode* root) {
    if (!root) return;

    if (!mp[root->val]) ans++;
    mp[root->val] = 1;

    f(root->left);
    f(root->right);
};

int numColor(TreeNode* root) {
    // int ans = 0;
    // unordered_map<int, int> mp;

    // auto f = [&](this auto&& f, TreeNode* root) -> void {
    //     if (!root) return;

    //     if (!mp[root->val]) ans++;
    //     mp[root->val] = 1;

    //     f(root->left);
    //     f(root->right);
    // };

    f(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
