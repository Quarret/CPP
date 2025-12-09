#include <bits/stdc++.h>
using ll = long long;
using namespace std;


bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size();
    vector memo(n + 1, vector<int>(m + 1, -1));

    if (s3.size() != n + m) {
        return false;
    }

    auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
        if (i < 0 && j < 0) return true;

        int &res = memo[i + 1][j + 1];
        if (res != -1) return res;
        res = (i >= 0 && s1[i] == s3[i + j + 1] && dfs(i - 1, j)) || 
                (j >= 0 && s2[j] == s3[i + j + 1] && dfs(i, j - 1));

        return res;
    };

    return dfs(n - 1, m - 1);
}

bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size();
    if (s3.size() != n + m) {
        return false;
    }


    vector f(n + 1, vector<int>(m + 1, 0));
    f[0][0] = 1;
    for (int j = 0; j < m; j++) {
        f[0][j + 1] = s2[j] == s3[j] && f[0][j];
    }

    for (int i = 0; i < n; i++) {
        f[i + 1][0] = s1[i] == s3[i] && f[i][0];
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && f[i][j + 1]) ||
                                (s2[j] == s3[i + j + 1] && f[i + 1][j]);
        }
    }

    return f[n][m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
