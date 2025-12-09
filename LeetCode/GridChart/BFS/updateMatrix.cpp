/*** 
 * @Author: Quarret
 * @Date: 2025-06-23 20:18:42
 * @LastEditTime: 2025-06-23 20:59:21
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
多源bfs要保证开始源之间平等
“源之间平等”的本质是：
初始条件平等：所有源点距离=0，同时开始
扩展规则平等：相同传播速度，相同处理优先级
目标函数平等：只关注最近源点，不偏好特定源
时空一致性：保证波前在时间和空间上的同步推进

如果本题拿1开始不能保证所有1都在同一层
0 0 0
0 1 0
1 1 1
明显 mat[2][1]与其他的到最近0的距离不等
所以这里从0开始，即使这个0不与1相邻也可加入队列，只需条件判断去除即可(这里mat[2][1]这个1就不能通过判断去除)
*/
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector<vector<int>> vis(m, vector<int>(n, 0)), ans(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) {
                vis[i][j] = 1;
                q.push({i, j});
                // q.emplace(i, j);
            }
        }
    }

    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();
        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                ans[nx][ny] = d;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
