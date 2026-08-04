#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 逆元 + 组合数
const int MOD = 1e9 + 7;
const int MX = 100001;

long long F[MX]; // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i! ^ -1 = (1 / i!) % MOD;

long long qpow(long long x, long long n) {
    long long res = 1;
    for (; n; n /= 2) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
    }

    return res;
}

int init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 2; i >= 0; i--) {
        INV_F[i] = INV_F[i + 1] * (i + 1) % MOD;
    }

    return 0;
}();

// 从 n 中选取 m 个数字 C(n, m)
long long comb(int n, int m) {
    return F[n] * INV_F[m] % MOD * INV_F[n - m];
}

class Solution {
public:
    int countVisiblePeople(int n, int pos, int k) {
        return comb(n - 1, k) * 2 % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}