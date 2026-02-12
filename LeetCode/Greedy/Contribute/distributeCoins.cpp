#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int distributeCoins(TreeNode* root) {
    int ans = 0;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
        if (!root) {
            return {0, 0};
        }

        auto [l_cnt, l_sum] = dfs(root->left);
        auto [r_cnt, r_sum] = dfs(root->right);
        int cnt = l_cnt + r_cnt + 1;
        int sum = l_sum + r_sum + root->val;
        
        // cout << cnt << ' ' << sum << '\n';
        ans += abs(cnt - sum);
        return {cnt, sum};
    };

    dfs(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}