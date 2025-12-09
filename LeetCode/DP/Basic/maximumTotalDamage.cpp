#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//due to soft, MLE
long long maximumTotalDamage(vector<int>& power) {
    // vector<long long> val(maxx + 1);
    unordered_map<int, long long> val;
    long long maxx = 0;
    for (long long x : power) {
        val[x] += x;
        maxx = max(maxx, x);
    }
    
    int n = val.size();
    // vector<long long> f(n + 3);
    long long f0 = 0, f1 = 0, f2 = 0;
    for (int i = 0; i <= maxx; i++) {
        // f[i + 3] = max(max(f[i + 2], f[i + 1]), f[i] + val[i]);
        long long new_f = max(max(f2, f1), f0 + val[i]);
        f0 = f1;
        f1 = f2;
        f2 = new_f;
    }

    return f2;
}

long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, int> cnt;
    for (int x : power) cnt[x]++;

    vector<pair<int, int>> a(cnt.begin(), cnt.end());
    sort(a.begin(), a.end());

    int n = a.size();
    vector<long long> f(n + 1);
    for (int i = 0, j = 0; i < n; i++) {
        auto [x, c] = a[i];
        while (a[j].first < x - 2) j++;//j is 1 bigger than really j

        f[i + 1] = max(f[i], f[j] + 1LL * x * cnt[x]);
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
