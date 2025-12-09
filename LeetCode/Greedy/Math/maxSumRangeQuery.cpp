#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    int n = nums.size();
    vector<long long> diff(n + 1);
    
    for (auto &q : requests) {
        diff[q[0]]++;
        diff[q[1] + 1]--;
    }

    int s = 0;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        s += diff[i];
        d[i] = s;
    }

    ranges::sort(nums);
    ranges::sort(d);

    int ans = 0;
    const int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        ans = (ans + 1LL * d[i] % MOD * nums[i] % MOD) % MOD;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
