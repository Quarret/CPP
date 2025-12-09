#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;

    auto dfs = [&](this auto&& dfs, TreeNode* root, string path) -> void {
        if (!root) return;
        
        string s = to_string(root->val) + "->";
        path += s;
        
        if (!root->left && !root->right) {
            path.pop_back();
            path.pop_back();
            ans.push_back(path);
            return;   
        }
        
        dfs(root->left, path);
        dfs(root->right, path);
    };

    dfs(root, "");
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
