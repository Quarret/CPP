#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector f(n + 1, vector<int>(m + 1, INT_MIN));
    
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = text1[i] == text2[j] ? f[i][j] + 1 : max(f[i][j + 1], f[i + 1][j]);
        }
    }

    return f[n][m];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector memo(n, vector<int>(m, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || j < 0) return 0;

        int &res = memo[i][j];
        if (res != -1) return res;
        res = text1[i] == text2[j] ? dfs(i - 1, j - 1) + 1 : max(dfs(i - 1, j), dfs(i, j - 1));

        return res;
    };

    return dfs(n - 1, m - 1);
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<int> f(m + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int topleft = 0;
        for (int j = 0; j < m; j++) {
            int tmp = f[j + 1];
            f[j + 1] = text1[i] == text2[j] ? topleft + 1 : max(f[j + 1], f[j]);
            topleft = tmp;
        }
    }

    return f[m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
