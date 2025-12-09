#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll qpow(ll x, ll y) {//x为底数，y为指数，ret为x^Y
    ll ret = 1;
    while (y) {
        if (y & 1) {
            ret = ret * x;
        }
        x = x * x;
        y >>= 1;
    }
    return ret;
}

