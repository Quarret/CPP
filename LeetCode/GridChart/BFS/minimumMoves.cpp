/*** 
 * @Author: Quarret
 * @Date: 2025-06-26 10:10:06
 * @LastEditTime: 2025-06-29 10:01:49
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
    尾 - 头  
    横 - 右 右 0
    横 - 右 下 1
    横 - 下 右 2
    横 - 下 下 3
    竖 - 右 右 4
    竖 - 右 下 5
    竖 - 下 右 6
    竖 - 下 下 7
    顺时针 8
    逆时针 9

当尾水平时，头一定在尾右
尾竖直时，头一定在尾下
*/

/*
做dfs与bfs这类题目主要难在题目理解与细节处
做题要理解清题目以及能够通过理解来的样例通过样例
还有就是实现遍历方向使用大量if-else
这种方法容易想，但大量的代码会将出现细节错误的概率变大
最好使用遍历来实现，难想但写对的概率更高
*/
int minimumMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    
    vector<vector<array<int, 10>>> vis(n, vector<array<int, 10>>(n, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    queue<array<int, 5>> q;
    q.push({0, 0, 0, 1, 0});
    q.push({0, 0, 0, 1, 1});

    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [r1, c1, r2, c2, dir] = q.front();
            if (r1 == n - 1 && c1 == n - 2 && r2 == n - 1 && c2 == n - 1) return d - 1;
            cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << ' ' << dir << '\n';
            q.pop();
            
            int nx1 = r1 + 1, ny1 = c1 + 1;
            int nx2 = r2 + 1, ny2 = c2 + 1;

            if (ny1 < n && ny2 < n && !grid[r2][ny2] && !grid[r1][ny1] && 
                ((!dir && !vis[r1][c1][2] && r2 == r1 + 1) || (!dir && !vis[r1][c1][0] && c2 == c1 + 1) || 
                (dir && r2 == r1 + 1 && !vis[r1][c1][6]) || (dir && c2 == c1 + 1 && !vis[r1][c1][4]))) {
                
                //cout << r1 << ' ' << ny1 << ' ' << r2 << ' ' << ny2 << ' '  << dir << '\n';
                q.push({r1, ny1, r2, ny2, dir});

                if (dir == 0 && r2 == r1 + 1) vis[r1][c1][2] = 1;
                else if (dir == 0 && c2 == c1 + 1) vis[r1][c1][0] = 1;
                else if (dir == 1 && r2 == r1 + 1) vis[r1][c1][6] = 1;
                else if (dir == 1 && c2 == c1 + 1) vis[r1][c1][4] = 1;
            }
            if (nx1 < n && nx2 < n && !grid[nx1][c1] && !grid[nx2][c2] && 
                ((!dir && c2 == c1 + 1 && !vis[r1][c1][1]) || (!dir && !vis[r1][c1][3] && r2 == r1 + 1) || 
                (dir && c2 == c1 + 1 && !vis[r1][c1][5] || (dir && r2 == r1 + 1 && !vis[r1][c1][7])))) {

                //cout << nx1 << ' ' << c1 << ' ' << nx2 << ' ' << c2 << ' ' << dir << '\n';
                q.push({nx1, c1, nx2, c2, dir});
                
                if (dir == 0 && c2 == c1 + 1) vis[r1][c1][1] = 1;
                else if (dir == 0 && r2 == r1 + 1) vis[r1][c1][3] = 1;
                else if (dir == 1 && c2 == c1 + 1) vis[r1][c1][5] = 1;
                else if (dir == 1 && r2 == r1 + 1) vis[r1][c1][7] = 1;
            }

            if (r1 == r2 && nx1 < n && nx2 < n && !grid[nx1][c1] && !grid[nx2][c2] && !dir && !vis[r1][c1][8]) {
                //cout << r1 << ' ' << c1 << ' ' << nx1 << ' ' << c1 << ' ' << 1 << '\n';
                q.push({r1, c1, nx1, c1, 1});
                vis[r1][c1][8] = 1;
            }

            if (c1 == c2 && ny1 < n && ny2 < n && !grid[r1][ny1] && !grid[r2][ny2] && dir && !vis[r1][c1][9]) {
                //cout << r1 << ' ' << c1 << ' ' << r1 << ' ' << ny1 << ' ' << 0 << '\n';
                q.push({r1, c1, r1, ny1, 0});
                vis[r1][c1][9] = 1;
            }

            //cout << '\n';
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
