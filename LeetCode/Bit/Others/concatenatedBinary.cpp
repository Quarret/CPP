#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int concatenatedBinary(int n) {
    long long ans = 1, MOD = 1e9 + 7;
    
    for (int i = 2; i <= n; i++) {
        int len = __bit_width(i);
        ans = ((ans << len) | i) % MOD;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
