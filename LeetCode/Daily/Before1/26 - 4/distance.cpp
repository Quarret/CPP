#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<long long> distance(vector<int>& nums) {
    using ll = long long;
    int n = nums.size();
    
    unordered_map<int, ll> cnt, sum, pre, cur_cnt;
    for (int i = 0; i < n; i++) {
        ll x = nums[i];
        sum[x] += i;
        cnt[x]++;
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ll x = nums[i];
        pre[x] += i;
        cur_cnt[x]++;

        ans[i] = cur_cnt[x] * i - pre[x] + sum[x] - pre[x] - (cnt[x] - cur_cnt[x]) * i;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}