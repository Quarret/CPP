#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector f(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i <= n; i++) f[i][0] = i;
    for (int i = 0; i <= m; i++) f[0][i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = word1[i] == word2[j] ? f[i][j] : min({f[i][j + 1], f[i + 1][j], f[i][j]}) + 1;
        }
    }

    return f[n][m];
}

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector memo(n, vector<int>(m, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        
        int &res = memo[i][j];
        if (res != -1) return res;
        res = word1[i] == word2[j] ? dfs(i - 1, j - 1) : min({dfs(i - 1, j - 1), dfs(i - 1, j), dfs(i, j - 1)}) + 1;
    
        return res;
    };

    return dfs(n - 1, m - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
