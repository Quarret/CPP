#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int monkeyMove(int n) {
    int ans = 1, x = 2, MOD = 1e9 + 7;
    while (n) {
        if (n & 1) {
            ans = (ans * x) % MOD;
        }

        x = (x * x) % MOD;
        n >>= 1;
    }
    
    return (ans % MOD - 2 % MOD + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
