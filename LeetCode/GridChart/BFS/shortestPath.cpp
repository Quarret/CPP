/*** 
 * @Author: Quarret
 * @Date: 2025-06-24 21:32:38
 * @LastEditTime: 2025-06-24 22:00:03
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
这题思考许久，但还是没有思路
有先找到不用删除墙来找最短路，然后二分最短路来check实现这个最短路长度是否满足破坏小于k个块，但check函数不会写 -> out
想到以每个墙为源来找相对应到最近目的地的最小路，但逻辑上明显有权限
从6/23晚上思考到6/24晚上还是没有思路

故看题解，题解思路大致是枚举所有破坏块的情况,在一遍bfs中跑完所有相同层不同破坏块的情况,在bfs下不同情况到达[m - 1, n - 1]都是最短的 
[x, y, rest]表示到达[x, y]块还剩rest个墙可以破坏
vis[x][y][rest]表示在剩余rest个块可以破坏的情况下到达[x, y]的情况
由于bfs的单调性，第一个到达[m - 1, n - 1]一定是所有情况中的最短路
*/

int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));

    if (m == 1 && n == 1) return 0;
    
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, k);
    vis[0][0][k] = 1;

    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y, rest] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (nx == m - 1 && ny == n - 1) return d;
                if (grid[nx][ny] && rest && !vis[nx][ny][rest - 1]) {
                    q.emplace(nx, ny, rest - 1);
                    vis[nx][ny][rest - 1] = 1;
                } else if (!grid[nx][ny] && !vis[nx][ny][rest]) {
                    q.emplace(nx, ny, rest);
                    vis[nx][ny][rest] = 1;
                }
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
