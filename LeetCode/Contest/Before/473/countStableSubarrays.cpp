#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long countStableSubarrays(vector<int>& capacity) {
    long long ans = 0, n = capacity.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + 1LL * capacity[i];
    }
    
    unordered_map<int, unordered_map<long long, long long>> mp;
    for (int i = 2; i < n; i++) {
        long long x = 1LL * pre[i + 1] - 3LL * capacity[i];
        mp[capacity[i - 2]][pre[i - 2]]++;

        ans += mp[capacity[i]][x];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
