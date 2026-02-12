#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    unordered_map<int, int> cnt;
    for (auto &p : points) {
        cnt[p[1]]++;
    }
    
    const int MOD = 1e9 + 7;
    long long s = 0;
    vector<long long> edges;
    for (auto [_, c] : cnt) {
        long long x = 1LL * c * (c - 1) / 2;
        s += x;
        edges.push_back(x);
    }

    long long ans = 0;
    for (int edge : edges) {
        long long x = edge * (s - edge);
        s -= edge;
        ans = (ans + x) % MOD;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
