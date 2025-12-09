#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> f(high + 1);
    f[0] = 1;
    int MOD = 1e9 + 7;
    
    for (int i = 1; i <= high; i++) {
        if (i - zero >= 0) f[i] = (f[i] + f[i - zero]) % MOD;
        if (i - one >= 0) f[i] = (f[i] + f[i - one]) % MOD;
    }

    int ans = 0;
    for (int i = low; i <= high; i++) {
        ans = (ans + f[i]) % MOD;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
