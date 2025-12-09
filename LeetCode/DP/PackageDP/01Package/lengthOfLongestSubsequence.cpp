#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    vector memo(n, vector<int>(target + 1, -1));
    
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0) return j == 0 ? 0 : INT_MIN;

        int &res = memo[i][j];
        if (res != -1) return res;
        res = dfs(i - 1, j);
        if (j >= nums[i]) res = max(res, dfs(i - 1, j - nums[i]) + 1);

        return res;
    };

    int ans = dfs(n - 1, target);
    return ans > 0 ? ans : -1;

    return dfs(n - 1, target) == -1 ? -1 : dfs(n - 1, target);
}

int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    vector f(n + 1, vector<int>(target + 1, INT_MIN));

    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            f[i + 1][j] = f[i][j];
            if (j >= nums[i]) f[i + 1][j] = max(f[i + 1][j], f[i][j - nums[i]] + 1);
        }
    }

    return f[n][target] > 0 ? f[n][target] : -1;
}


int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> f(target + 1, INT_MIN);

    f[0] = 0;
    for (int x : nums) {
        for (int c = target; c >= x; c--) {
            f[c] = max(f[c], f[c - x] + 1);
        }
    }

    return f[target] > 0 ? f[target] : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
