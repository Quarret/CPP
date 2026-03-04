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
 
class Solution {
public:
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        long long s = 0;

        auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
            if (!root) {
                return;
            }

            s += root->val;
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);

        long long ans = 0;
        // auto cal = [&](this auto&& cal, TreeNode* root) -> long long {
        //     if (!root) {
        //         return 0;
        //     }

        //     long long left = cal(root->left);
        //     long long right = cal(root->right);

        //     ans = max({ans, (s - left) * left, (s - right) * right});

        //     return left + right + 1LL * root->val;
        // };

        auto cal = [&](this auto&& cal, TreeNode* root) -> long long {
            if (!root) {
                return 0;
            }

            long long left = cal(root->left);
            long long right = cal(root->right);
            long long res = left + right + root->val;

            ans = max(ans, (s - res) * res);

            return res;
        };
        cal(root);

        return ans % MOD;
    };
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}