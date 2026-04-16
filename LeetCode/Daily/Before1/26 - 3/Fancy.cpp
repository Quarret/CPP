#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Fancy {
    static constexpr int MOD = 1e9 + 7;

    vector<int> vals;
    long long add = 0, mul = 1;

    long long qpow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res % MOD;
    }

public:
    Fancy() {
        
    }
    
    void append(int val) {
        vals.push_back((val - add + MOD) * qpow(mul, MOD - 2) % MOD);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        add = add * m % MOD;
        mul = mul * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= vals.size()) {
            return -1;
        }
        return (vals[idx] * mul + add) % MOD;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}