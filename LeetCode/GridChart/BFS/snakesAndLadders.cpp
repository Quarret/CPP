/*** 
 * @Author: Quarret
 * @Date: 2025-06-25 10:36:32
 * @LastEditTime: 2025-06-26 11:36:50
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> board = {{-1,-1,-1},{-1,9,8},{-1,8,9}};
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(n, vector<int>(2, 0)));
    queue<array<int, 3>> q;
    q.push({n - 1, 0, 1});

    auto checkx = [&](int num) -> int {
        return (n - 1) - (num - 1) / n;
    };

    auto checky = [&](int num, int nx) -> int {
        return nx % 2 == (n - 1) % 2 ? (num - 1) % n : n - 1 - (num - 1) % n;
    };

    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto[x, y, num] = q.front();
            q.pop();

            for (int k = 1; k <= 6; k++) {
                int num1 = min(num + k, n * n);
                int nx = checkx(num1);
                int ny = checky(num1, nx);

                if (num1 == n * n) return d;
                if (vis[nx][ny][1]) continue;
                if (board[nx][ny] == -1) {
                    vis[nx][ny][1] = 1;
                    q.push({nx, ny, num1});
                } else if (board[nx][ny] != -1) {
                    int num2 = board[nx][ny];
                    nx = checkx(num2);
                    ny = checky(num2, nx);

                    if (num2 == n * n) return d;
                    if (vis[nx][ny][0]) continue;;
                    vis[nx][ny][0] = 1;
                    q.push({nx, ny, num2});
                }
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    snakesAndLadders(board);

    return 0;
}
