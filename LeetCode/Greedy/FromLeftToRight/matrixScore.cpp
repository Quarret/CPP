#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][0] == 1) break;
            grid[i][j] ^= 1;
        }
    }

    for (int j = 0; j < n; j++) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < m; i++) {
            (grid[i][j] == 1 ? cnt1 : cnt0) += 1;
        }

        if (cnt0 > cnt1) {
            for (int i = 0; i < m; i++) {
                grid[i][j] ^= 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            res = (res << 1) | grid[i][j];
        }
        ans += res;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
