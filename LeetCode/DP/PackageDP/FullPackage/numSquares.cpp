#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numSquares(int n) {
    int m = sqrt(n);
    vector f(m + 2, vector<int>(n + 1, 1e9));
    
    f[0][0] = 0;
    for (int x = 0; x <= m; x++) {
        for (int c = 0; c <= n; c++) {
            if (c >= x * x) f[x + 1][c] = min(f[x][c], f[x + 1][c - x * x] + 1);
            else f[x + 1][c] = f[x][c];
        }
    }

    return f[m + 1][n];
}


int numSquares(int n) {
    int m = sqrt(n);
    vector<int> f(n + 1, 1e9);

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
    cin.tie(NULL);

    

    return 0;
}
