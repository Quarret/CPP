/*** 
 * @Author: Quarret
 * @Date: 2025-06-22 20:05:01
 * @LastEditTime: 2025-06-22 21:58:51
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
[["+",".","+","+","+","+","+"],
["+",".","+",".",".",".","+"],
["+",".","+",".","+",".","+"],
["+",".",".",".",".",".","+"],
["+","+","+","+",".","+","."]]
*/

/*
dfs由于是递归调用的，每次只能对一个块的一个方向(深度优先)进行搜索
由于这种优先策略导致访问顺序不一定最佳
*/
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size(), n = maze[0].size(), ans = 1e9;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int i, int j, int cnt) -> void {
        maze[i][j] = '+';
        cnt++;

        for (int k = 0; k < 4; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '+') continue;
            if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
                ans = min(ans, cnt);
                continue;
            }
            dfs(nx, ny, cnt);
        }
        maze[i][j] = '.';
    };

    dfs(entrance[0], entrance[1], 0);

    return (ans == 1e9 ? - 1 : ans);
}

/*
bfs广度优先，优先对一个块的所有方向进行搜索,一层一层深入,这样保证队列中块离源块的距离是非递减的
故当某一层第一次找到目标快，则此时的距离一定是最小的
《利用队列的FIFO特性实现层序遍历》
*/
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size(), n = maze[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    queue<tuple<int, int, int>> q;

    q.emplace(entrance[0], entrance[1], 0);
    maze[entrance[0]][entrance[1]] = '+';

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + next[k][0];
            int ny = y + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '+') continue;
            if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) return cnt + 1;
            q.emplace(nx, ny, cnt + 1);
            maze[nx][ny] = '+';
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
