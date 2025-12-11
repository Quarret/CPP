#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countTriples(int n) {
    int ans = 0;
    for (int a = 1; a <= n - 2; a++) {
        for (int b = 1; b <= n - 1; b++) {
            for (int c = b; c <= n; c++) {
                if (a * a + b * b == c * c) {
                    ans++;
                }
            }
        }
    }
    
    return ans;
}

int countTriples(int n) {
    int ans = 0;
    for (int a = 1; a < n; a++) {
        for (int b = 1; b < a && a * a + b * b <= n * n; b++) {
            int c2 = a * a + b * b;
            int rt2 = sqrt(c2);
            if (rt2 * rt2 == c2) {
                ans++;
            }
        }
    }
    
    return ans * 2;
}

// 本原勾股数组
// gcd(a, b) = gcd(a, c) = gcd(b, c) = 1
// (a, b) 必是一奇一偶
// gcd(c + b, c - b) = 1
// c + b = u^2, c - b = v^2, u, v 必是奇数
// gcd(u, v) = 1
int countTriples(int n) {
    int ans = 0;
    for (int u = 3; u * u < 2 * n; u += 2) {
        for (int v = 1; v < u && v * v + u * u <= 2 * n; v += 2) {
            if (gcd(u, v) == 1) {
                ans += 2 * n / (u * u + v * v);
            }
        }
    }

    return ans * 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
