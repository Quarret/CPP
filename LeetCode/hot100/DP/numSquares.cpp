#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numSquares(int n) {
    int m = sqrt(n);
    vector<int> f(n + 1, INT_MAX / 2);

    f[0] = 0;
    for (int x = 0; x <= m; x++) {
        for (int c = x * x; c <= n; c++) {
            f[c] = min(f[c], f[c - x * x] + 1);
        }
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}