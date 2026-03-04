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

// 数学 + 逆元
class Solution {
    static constexpr int MOD = 1e9 + 7;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }

        return res;
    }
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int w = 1; 1 << (w - 1) <= n; w++) {
            // 二进制长度为 w 的上下界
            int l = 1 << (w - 1);
            int r = min((1 << w) - 1, n);
            // 区间内数字个数
            int m = r - l + 1;
            // 长度 w 的基底
            int q = 1 << w;

            long long pow_q = pow(q, m);
            // (q - 1) 的逆元
            long long inv_q1 = pow(q - 1, MOD - 2);  
            long long s = r * (pow_q - 1) % MOD * inv_q1 - 
                            (q - m * pow_q % MOD + (m - 1) * pow_q % MOD * q) % MOD * inv_q1 % MOD * inv_q1; 
            ans = (ans * pow_q + s) % MOD;
        }
        return (ans + MOD) % MOD;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
