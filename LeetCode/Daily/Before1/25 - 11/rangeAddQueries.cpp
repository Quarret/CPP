#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector ans(n, vector<int>(n, 0));
    
    for (auto &e : queries) {
        int r1 = e[0], c1 = e[1];
        int r2 = e[2], c2 = e[3];

        for (int i = r1; i <= r2; i++) {
            ans[i][c1]++;
            if (c2 < n - 1) ans[i][c2 + 1]--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            ans[i][j] = ans[i][j - 1] + ans[i][j];
        }
    }

    return ans;
}

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector diff(n + 2, vector<int>(n + 2, 0));
    for (auto &q : queries) {
        int r1 = q[0], c1 = q[1];
        int r2 = q[2], c2 = q[3];

        diff[r1 + 1][c1 + 1]++;
        diff[r1 + 1][c2 + 2]--;
        diff[r2 + 2][c1 + 1]--;
        diff[r2 + 2][c2 + 2]++;
    }
    
    vector ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diff[i + 1][j + 1] += diff[i + 1][j] + diff[i][j + 1] - diff[i][j];
            ans[i][j] = diff[i + 1][j + 1];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
