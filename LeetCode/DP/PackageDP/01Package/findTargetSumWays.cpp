#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    target += reduce(nums.begin(), nums.end());
    if (target % 2 || target < 0) return false;
    
    vector memo(n, vector<int>(target / 2 + 1, -1));
    auto dfs = [&](this auto&& dfs, int i, int c) -> int {
        if (i < 0) return c == 0 ? 1 : 0;

        int &res = memo[i][c];
        if (res != -1) return res;
        res = 0;
        if (c >= nums[i]) res += dfs(i - 1, c - nums[i]);
        res += dfs(i - 1, c);
        return res;
    };

    return dfs(n - 1, target / 2);
}


int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    target += reduce(nums.begin(), nums.end());
    if (target % 2 || target < 0) return false;
    
    target /= 2;
    vector f(n + 1, vector<int>(target + 1, 0));
    f[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            f[i + 1][j] = f[i][j] + (j >= nums[i] ? f[i][j - nums[i]] : 0);
        }
    }

    return f[n][target];
}


int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    target += reduce(nums.begin(), nums.end());
    if (target % 2 || target < 0) return false;
    
    target /= 2;
    vector<int> f(target + 1);
    f[0] = 1;

    for (int x : nums) {
        for (int c = target; c >= x; c--) {
            f[c] += f[c - x];
        }
    }

    return f[target];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
