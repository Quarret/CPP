#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector memo(n, vector<int>(m, -1));
    
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || j < 0) return 0;

        int &res = memo[i][j];
        if (res != -1) return res;
        res = word1[i] == word2[j] ? dfs(i - 1, j - 1) + 1 : max(dfs(i - 1, j), dfs(i, j- 1));
        return res;
    };

    return m + n - 2 * dfs(n - 1, m - 1);
}

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> f(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int topleft = f[0];
        for (int j = 0; j < m; j++) {
            int tmp = f[j + 1];
            f[j + 1] = word1[i] == word2[j] ? topleft + 1 : max(f[j + 1], f[j]);
            topleft = tmp;
        }
    }

    return m + n - 2 * f[m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
