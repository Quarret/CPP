#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// 枚举选哪个 DP
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, 0);
    
    auto dfs = [&](this auto&& dfs, int i) -> int {
        int &res = memo[i];
        if (res != 0) return res;

        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                res = max(res, dfs(j));
            }
        }

        res += 1;
        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // ans = max(ans, memo[i]);
        ans = max(ans, dfs(i));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}