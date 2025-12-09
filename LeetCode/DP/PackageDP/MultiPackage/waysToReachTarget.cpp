#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int waysToReachTarget(int target, vector<vector<int>>& types) {
    int n = types.size(), MOD = 1e9 + 7;
    vector<int> f(target + 1, 0);

    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int count = types[i][0], mask = types[i][1];
        for (int j = target; j >= mask; j--) {
            for (int k = 1; k <= min(j / mask, count); k++) {
                f[j]  = (f[j] + f[j - k * mask]) % MOD;
            }
        }
    }

    return f[target];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
