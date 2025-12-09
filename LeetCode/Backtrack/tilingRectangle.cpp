#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int tilingRectangle(int n, int m) {
    vector covered(n, vector<int>(m, 0));
    int ans = 14 * 14;

    auto dfs = [&](this auto&& dfs, int x, int y, int cnt) -> void {
        if (cnt >= ans) return;
        bool full = true;
        int row, col;
        for (int i = 0; i < n && full; i++) {
            for (int j = 0; j < m && full; j++) {
                if (!covered[i][j]) {
                    full = false;
                    row = i;
                    col = j;
                }
            }
        }

        if (full) {
            ans = min(ans, cnt);
            return;
        }

        for (int len = min(n - row, m - col); len >= 1; len--) {
            bool isEmpty = true;
            for (int i = row; i < row + len && isEmpty; i++) {
                for (int j = col; j < col + len && isEmpty; j++) {
                    if (covered[i][j]) {
                        isEmpty = false;
                    }
                }
            }

            if (!isEmpty) continue;

            for (int i = row; i < row + len; i++) {
                for (int j = col; j < col + len; j++) {
                    covered[i][j] = 1;
                }
            }

            dfs(n, m, cnt + 1);

            for (int i = row; i < row + len; i++) {
                for (int j = col; j < col + len; j++) {
                    covered[i][j] = 0;
                }
            }
        }
    };

    dfs(n, m, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
