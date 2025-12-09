#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    int t = strs.size();
    vector<int> cnt0(t, 0), cnt1(t, 0);
    
    for (int i = 0; i < t; i++) {
        for (char c : strs[i]) {
            (c == '1' ? cnt1[i] : cnt0[i]) += 1;
        }
    }

    vector memo(t, vector(m + 1, vector<int>(n + 1, -1)));
    auto dfs = [&](this auto&& dfs, int i, int m, int n) -> int {
        if (m < 0 || n < 0) {
            return INT_MIN / 2;
        }

        if (i < 0) {
            return 0;
        }

        int &res = memo[i][m][n];
        if (res != -1) return res;
        res = max(dfs(i - 1, m, n), dfs(i - 1, m - cnt0[i], n - cnt1[i]) + 1);
        
        return res;
    };

    return dfs(t - 1, m, n);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector f(m + 1, vector<int>(n + 1));

    for (string s : strs) {
        int cnt0 = ranges::count(s, '0');
        int cnt1 = s.size() - cnt0;
        for (int j = m; j >= cnt0; j--) {
            for (int k = n; k >= cnt1; k--) {
                f[j][k] = max(f[j][k], f[j - cnt0][k - cnt1] + 1);
            }
        }
    }

    return f[m][n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
