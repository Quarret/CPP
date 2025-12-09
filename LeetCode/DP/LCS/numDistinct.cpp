#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector f(n + 1, vector<unsigned>(m + 1, 0));

    for (int i = 0; i <= n; i++) f[i][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = s[i] == t[j] ? f[i][j] + f[i][j + 1] : f[i][j + 1]; 
        }
    }

    return f[n][m];
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector memo(n, vector<long long>(m, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
        if (j < 0) return 1;
        if (i < 0) return 0;

        long long &res = memo[i][j];
        if (res != -1) return res;
        res = s[i] == t[j] ? dfs(i - 1, j - 1) + dfs(i - 1, j) : dfs(i - 1, j);

        return res;
    };

    return dfs(n - 1, m - 1);
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<unsigned> f(m + 1, 0);

    f[0] = 1;    
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            f[j + 1] = s[i] == t[j] ? f[j + 1] + f[j] : f[j + 1];
        }
    }

    return f[m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
