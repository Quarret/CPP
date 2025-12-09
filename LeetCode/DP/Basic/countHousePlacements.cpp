#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countHousePlacements(int n) {
    int MOD = 1e9 + 7;
    vector<int> f(n + 2);
    f[0] = 2, f[1] = 3;
    
    for (int i = 2; i < n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }

    long long ans = (1LL * f[n - 1] * f[n - 1]) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
