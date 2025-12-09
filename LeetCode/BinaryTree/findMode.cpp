#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;



vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int pre = -1e9, cnt = 0, maxx = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        dfs(root->left);
        if (root->val != pre && pre != -1e9) {
            if (cnt == maxx) ans.push_back(pre);
            else if (cnt > maxx) {
                ans.clear();
                ans.push_back(pre);
                maxx = max(cnt, maxx);
            }
            cnt = 1;
        }
        else cnt++;
        pre = root->val;
        dfs(root->right);
    };
    
    dfs(root);
    if (cnt == maxx && ans.back() != pre) ans.push_back(pre);
    else if (cnt > maxx) {
        ans.clear();
        ans.push_back(pre);
    }

    return ans;
}

// 先判断是否不同, 再cnt++, 少写特判
vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int pre = -1e9, cnt = 0, maxx = 0;
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;
        
        dfs(root->left);
        if (root->val != pre) {
            cnt = 0;
            pre = root->val;
        }
        cnt++;

        if (cnt == maxx) ans.push_back(root->val);
        else if (cnt > maxx) {
            ans.clear();
            ans.push_back(root->val);
            maxx = cnt;
        }
        dfs(root->right);
    };
    
    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
