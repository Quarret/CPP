#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    int t = strs.size();
    vector<int> cnt0(t, 0), cnt1(t, 0);
    
    for (int i = 0; i < t; i++) {
        for (char c : strs[i]) {
            if (c == '0') cnt0[i]++;
            else cnt1[i]++;
        }
    }

    // vector f(t + 1, vector(m + 1, vector<int>(n + 1, 0)));
    // for (int i = 0; i < t; i++) {
    //     int c1 = cnt0[i], c2 = cnt1[i];
    //     for (int j = 0; j <= m; j++) {
    //         for (int k = 0; k <= n; k++) {
    //             if (j >= c1 && k >= c2) f[i + 1][j][k] = max(f[i][j][k], f[i][j - c1][k - c2] + 1);
    //             else f[i + 1][j][k] = f[i][j][k]; // 即使装不下这个字符串也要转移状态
    //         }
    //     }
    // }

    // return f[t][m][n];

    vector f(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < t; i++) {
        int c1 = cnt0[i], c2 = cnt1[i];
        for (int j = m; j >= cnt0[i]; j--) {
            for (int k = n; k >= cnt1[i]; k--) {
                f[j][k] = max(f[j][k], f[j - c1][k - c2] + 1);
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
