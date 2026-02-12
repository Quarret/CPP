#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
    using ll = long long;
    ll n = arr.size();

    vector<int> arr_idx(n), brr_idx(n);
    ranges::iota(arr_idx, 0);    
    ranges::iota(brr_idx, 0);
    ranges::sort(arr_idx, {}, [&](auto &i) {
        return arr[i];
    });
    ranges::sort(brr_idx, {}, [&](auto &i) {
        return brr[i];
    });

    ll ans = 0, ok = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int a_idx = arr_idx[i];
        int b_idx = brr_idx[i];
        if (a_idx != b_idx) ok = 1;
        ans += 1LL * abs(arr[i] - brr[i]);
        res += 1LL * abs(arr[a_idx] - brr[b_idx]);
    }

    return min(res + k * ok, ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}