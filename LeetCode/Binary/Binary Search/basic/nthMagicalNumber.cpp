#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long MOD = 1e9 + 7;
int nthMagicalNumber(int n, int a, int b) {
    long long l = 1, r = (long long)n * min((long long)a, (long long)b) + 1, mid = 0;
    long long c = a * b / gcd(a, b);

    auto check = [&](long long x) -> bool {
        long long cnt = 0;
        cnt += x / a;
        cnt += x / b;
        cnt -= x / c;

        return cnt >= n;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
