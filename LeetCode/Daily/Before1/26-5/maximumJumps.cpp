#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> memo(n);

    auto dfs = [&](this auto&& dfs, int j) -> int {
        if (j == 0) return 0;

        int &res = memo[j];
        if (res) return res;

        res = INT_MIN;
        for (int i = 0; i < j; i++) {
            if (abs(nums[i] - nums[j]) > target) continue;
            res = max(res, dfs(i) + 1);
        }

        return res;
    };

    int ans = dfs(n - 1);
    return ans < 0 ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}