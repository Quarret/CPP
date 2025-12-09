#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
两个数求lcm是准的
多个数就不一定了
2 2 4
2 4 7
*/
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}
int nthUglyNumber(int n, int a, int b, int c) {
    long long l = 0, r = n * min((long long)a, min((long long)b, (long long)c)) + 1, mid = 0;
    long long d1 = lcm((long long)a, (long long)b);
    long long d2 = lcm((long long)a, (long long)c);
    long long d3 = lcm((long long)c, (long long)b);
    long long d4 = lcm(d3, (long long)a);
    // 错误写法
    // long long d4 = (long long)a * (long long)b * (long long)c / gcd((long long)a, gcd((long long)b, (long long)c));
    
    auto check = [&](long long x) -> bool {
        long long cnt = 0;
        cnt += x / a + x / b + x / c;
        cnt -= x / d1 + x / d2 + x / d3;
        cnt += x / d4;
        
        return cnt >= n;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    nthUglyNumber(25, 2, 4, 7);

    return 0;
}
