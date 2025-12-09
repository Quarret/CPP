#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int largestIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), num = 2, cnt = 0;
    unordered_map<int, int> mp;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        grid[i][j] = num;
        cnt++;

        for (int k = 0; k < 4; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
            dfs(nx, ny);
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cnt = 0;
                dfs(i, j);
                mp[num++] = cnt;
            }
        }
    }

    //少用函数调用，创建新的栈以及回收耗时严重!!!
    //不涉及递归操作的时候，少用!!!
    // auto sum = [&](int i, int j, unordered_map<int, pair<int,int>> mp) -> int {
    //     int res = 1;

    //     for (int k = 0; k < 4; k++) {
    //         int nx = i + next[k][0];
    //         int ny = j + next[k][1];

    //         if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0 && !mp[grid[nx][ny]].second) {
    //             mp[grid[nx][ny]].second = 1;
    //             res += mp[grid[nx][ny]].first;
    //         }
    //     }
        
    //     return res;
    // };

    int ans = 0;
    unordered_set<int> st;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                int res = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = i + next[k][0];
                    int ny = j + next[k][1];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0 && st.find(grid[nx][ny]) == st.end()) {
                        res += mp[grid[nx][ny]];
                        st.insert(grid[nx][ny]);
                    }
                }
                ans = max(ans, res);
                st.clear();
            }
        }
    }

    return ans == 0 ? n * m : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
