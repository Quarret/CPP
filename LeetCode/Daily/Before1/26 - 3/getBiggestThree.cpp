#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    set<int> st;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            st.insert(grid[i][j]);
            for (int r = 1; r <= min({i, m - 1 - i, j, n - 1 - j}); r++) {
                int sum = 0;
                sum += grid[i - r][j] + grid[i][j - r] + grid[i + r][j] + grid[i][j + r];
                for (int x = 1; x < r; x++) {
                    int y = r - x;
                    sum += grid[i - x][j - y] + grid[i - x][j + y] 
                            + grid[i + x][j - y] + grid[i + x][j + y];
                }
                st.insert(sum);
            }
        }
    }

    vector<int> ans;
    auto it = st.rbegin();
    for (int i = 0; i < 3 && it != st.rend(); i++, it++) {
        ans.push_back(*it);
    }
    return ans;
}

// 对角线前缀和
vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector diag_sum(m + 1, vector<int>(n + 1)); // 左下对角线前缀和
    vector anti_sum(m + 1, vector<int>(n + 1)); // 右下对角线前缀和
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = grid[i][j];
            diag_sum[i + 1][j + 1] = diag_sum[i][j] + x;
            // anti_sum[i][j] = anti_sum[i - 1][j + 1] + x
            anti_sum[i + 1][j] = anti_sum[i][j + 1] + x;
        }
    }

    // 从 (x, y) 开始沿左下方向 k 个数的和
    auto query_diag = [&](int x, int y, int k) -> int {
        return diag_sum[x + k][y + k] - diag_sum[x][y];
    };

    // 这个要按前面 anti 的下标来理解
    auto query_anti = [&](int x, int y, int k) -> int {
        return anti_sum[x + k][y + 1 - k] - anti_sum[x][y + 1];
    };

    int x = 0, y = 0, z = 0;

    auto update = [&](int v) -> void {
        if (v > x) {
            z = y;
            y = x;
            x = v;
        } else if (v > y && v < x) {
            z = y;
            y = v;
        } else if (v > z && v < y) {
            z = v;
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            update(grid[i][j]);

            int mx = min({i, j, m - 1 - i, n - 1- j});
            for (int r = 1; r <= mx; r++) {
                int a = query_diag(i - r, j, r + 1); // 右上边
                int b = query_diag(i, j - r, r + 1); // 左下边
                int c = query_anti(i - r, j, r + 1); // 左上边
                int d = query_anti(i, j + r, r + 1); // 右下边
                int sum = a + b + c + d - grid[i - r][j] - grid[i + r][j] - grid[i][j - r] - grid[i][j + r];
                update(sum);
            }
        }
    }

    vector<int> ans{x, y, z};
    while (ans.back() == 0) {
        ans.pop_back();
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}