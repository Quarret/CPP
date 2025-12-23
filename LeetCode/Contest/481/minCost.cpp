#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minCost(string s, vector<int>& cost) {
    unordered_map<int, long long> mp;
    int n = s.size();
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        mp[s[i] - 'a'] += 1LL * cost[i];
        sum += 1LL * cost[i];
    }

    long long ans = INT64_MAX;
    for (auto [_, c] : mp) {
        ans = min(ans, sum - c);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
