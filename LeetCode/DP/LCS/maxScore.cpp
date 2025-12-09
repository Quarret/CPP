#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maxScore(vector<int>& a, vector<int>& b) {
    int m = b.size();
    vector memo(4, vector<long long>(m, INT64_MIN));

    auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
        if (i < 0) return 0;
        if (j < 0) return INT64_MIN / 2;

        long long &res = memo[i][j];
        if (res != INT32_MIN) return res;
        res = max(dfs(i, j - 1), dfs(i - 1, j - 1) + a[i] * b[j]);
        
        return res;
    };

    return dfs(3, m - 1);
}

long long maxScore(vector<int>& a, vector<int>& b) {
    int m = b.size();
    vector f(5, vector<long long>(m + 1, INT64_MIN));

    for (int i = 0; i <= 4; i++) f[i][0] = INT64_MIN / 2;
    for (int j = 0; j <= m; j++) f[0][j] = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = max(f[i][j] + 1LL * a[i] * b[j], f[i + 1][j]);
        }
    }

    return f[4][m];
}

long long maxScore(vector<int>& a, vector<int>& b) {
    int m = b.size();
    vector<long long> f(5, INT64_MIN / 2);

    f[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 3; j >= 0; j--) {
            f[j + 1] = max(f[j + 1], f[j] + 1LL * a[j] * b[i]);
        }
    }

    return f[4];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
