#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 不相邻DP
long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, int> mp;
    for (int x : power) {
        mp[x]++;
    }
    
    vector<pair<int, int>> a(mp.begin(), mp.end());
    sort(a.begin(), a.end());
    int n = a.size();

    vector<long long> f(n + 1, 0);
    for (int i = 0, j = 0; i < n; i++) {
        auto [x, c] = a[i];
        while (a[j].first < x - 2) j++;
        
        f[i + 1] = max(f[i], f[j] + 1LL * x * c);
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
