#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    if (n < 3) return 0;
    
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int score = 0;
        vector<int> a;
        for (int j = i; ; j += 2) {
            if (a.size() == n / 2) {
                score += minScoreTriangulation(a);
                break;
            }
            a.push_back(values[j % n]);
            score += values[j % n] * values[(j + 1) % n] * values[(j + 2) % n];
        }
        ans = min(ans, score);
    }

    return ans;
}

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector memo(n, vector<int>(n, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (j == i + 1) return 0;

        int &res = memo[i][j];
        if (res != -1) return res;
        
        res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
        }

        return res;
    };

    return dfs(0, n - 1);
}

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector f(n, vector<int>(n, 0));

    for (int i = n - 3; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            f[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
            }
        }
    }

    return f[0][n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
