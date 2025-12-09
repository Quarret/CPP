#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
费马小定理：
当y为质数时， x ^ (y - 1) mod MOD = 1;
所以 x ^ (y - 2) mod MOD = x ^ (-1);
所以通过快速幂来求逆元
*/
const int MOD = 998244353;
ll qpow(ll x, ll y, ll MOD) {//x为底数，y为指数，ret为x^y
    ll ret = 1;
    while (y) {
        if (y & 1) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}



