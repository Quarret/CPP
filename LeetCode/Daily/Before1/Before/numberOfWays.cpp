#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfWays(int n, int x) {
    vector<long long> f(n + 1);
    
    for (int i = 1; pow(i, x) <= n; i++) {
        int v = pow(i, x);
        for (int s = n; s >= v; s--) {
            f[s] += f[s - v];
        }
    }

    int MOD = 1e9 + 7;
    return f[n] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
