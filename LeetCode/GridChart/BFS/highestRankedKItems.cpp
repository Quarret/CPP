/*** 
 * @Author: Quarret
 * @Date: 2025-06-24 09:08:21
 * @LastEditTime: 2025-06-24 09:47:27
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
    int m = grid.size(), n = grid[0].size(), d = 0;;
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> ans;

    queue<pair<int, int>> q;
    q.emplace(start[0], start[1]);
    vis[start[0]][start[1]] = 1;
    if (!(grid[start[0]][start[1]] < pricing[0] || grid[start[0]][start[1]] > pricing[1])) ans.push_back({start[0], start[1]});

    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] || !grid[nx][ny]) continue;
                vis[nx][ny] = d + 1;
                q.emplace(nx, ny);
                if (!(grid[nx][ny] < pricing[0] || grid[nx][ny] > pricing[1])) ans.push_back({nx, ny});
            }
        }

        if (ans.size() >= k) break;
    }


    sort(ans.begin(), ans.end(), [&](vector<int>& p1, vector<int>& p2) {
        if (vis[p1[0]][p1[1]] < vis[p2[0]][p2[1]]) return 1;
        else if (vis[p1[0]][p1[1]] == vis[p2[0]][p2[1]]) {
            if (grid[p1[0]][p1[1]] < grid[p2[0]][p2[1]]) return 1;
            else if (grid[p1[0]][p1[1]] == grid[p2[0]][p2[1]]) {
                if (p1[0] < p2[0]) return 1;
                else if (p1[0] == p2[0]) {
                    if (p1[1] < p2[1]) return 1;
                    else return 0;
                }  else return 0;
            } else return 0;
        } else return 0;
    });

    while (ans.size() > k) ans.pop_back();

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
