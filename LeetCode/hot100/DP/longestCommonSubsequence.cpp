#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// LCS dfs(i, j) 表示末尾为 s[i], t[j] 时的最大公共子序列长度
int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector memo(n, vector<int>(m, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || j < 0) { // 一方剩余长度为 0, 没有公共子序列
            return 0;
        }

        int &res = memo[i][j];
        if (res != -1) return res;

        if (s[i] == t[j]) res = dfs(i - 1, j - 1) + 1;
        else res = max(dfs(i - 1, j), dfs(i, j - 1));
    
        return res;
    };

    return dfs(n - 1, m - 1);
}

int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector f(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) f[i + 1][j + 1] = f[i][j] + 1;
            else f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
        }
    }

    return f[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}