/*** 
 * @Author: Quarret
 * @Date: 2025-07-02 16:14:56
 * @LastEditTime: 2025-07-02 18:39:26
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
一开始拿到这题是懵的
最短路 bfs很明显
但终点是多个的，之前做的最短路都是单终点
刚开始还是想的，还是之前三个状态[x, y, sp]来表示，收集完所有垃圾即可
后面细想：bfs是层层推进的，路径A收集到垃圾1，路径B收集到垃圾2，是收集完了，但所走的步数肯定不是简单的d1 + d2

那有什么办法能够准确的描述当前收集到的垃圾数 --- 再拿一个状态量来表示 [x, y, sp, mask]
*/
vector<string> classroom = {"S.", "XL"};
int minMoves(vector<string>& classroom, int energy) {
    int m = classroom.size(), n = classroom[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int sx = 0, sy = 0, trash = 0;
    vector<vector<int>> idx(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (classroom[i][j] == 'S') {
                sx = i, sy = j;
            } else if (classroom[i][j] == 'L') {
                idx[i][j] = 1 << trash++;
            }
        }
    }

    int u = 1 << trash;
    vector vis(m, vector(n, vector(energy + 1, vector<int8_t>(u, 0))));
    
    queue<array<int, 4>> q;
    q.push({sx, sy, energy, 0});
    vis[sx][sy][energy][0] = 1;
    
    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y, sp, mask] = q.front();
            q.pop();
            if (mask == u - 1) return d - 1;//统一判断，避免corner case

            for (auto& [dx, dy]: next) {
                int nx = x + dx;
                int ny = y + dy;
                int nsp = 0, nmask = 0;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') continue;
                nsp = classroom[nx][ny] == 'R' ? energy : sp - 1;
                nmask = mask | idx[nx][ny];
                if (vis[nx][ny][nsp][nmask]) continue;
                vis[nx][ny][nsp][nmask] = 1;
                q.push({nx, ny, nsp, nmask}); 
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minMoves(classroom, 2);

    return 0;
}
