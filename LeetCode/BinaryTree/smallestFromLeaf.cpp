#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

string smallestFromLeaf(TreeNode* root) {
    auto cmp = [&](string s1, string s2) -> string {
        int n = s1.size(), m = s2.size();
        for (int i = 0; i < min(n, m); i++) {
            if (s1[i] < s2[i]) return s1;
            else if (s1[i] > s2[i]) return s2;
        }

        return n > m ? s2 : s1;
    };

    string ans = "";
    auto dfs = [&](this auto&& dfs, TreeNode* root, string path) -> void {
        if (!root) return;

        path += root->val + 'a';
        if (!root->left && !root->right) {
            string s = path;
            reverse(s.begin(), s.end());
            ans = ans == "" ? s : cmp(ans, s);
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
