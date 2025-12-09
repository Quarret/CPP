#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    int MOD = 1e9 + 7;
    vector<int> f(target + 1, 0);
    
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= target - i; j++) {
            for (int t = 1; t <= k && t <= j; t++) {
                f[j] = (f[j] + f[j - t]) % MOD;
            }
        }
    }
    
    return f[target] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
