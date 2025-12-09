#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int next[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        vis[i][j] = 1;

        int cnt = 0;
        for (int k = 0; k < 8; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 'M') cnt++;
        }

        if (cnt != 0) {
            board[i][j] = cnt + '0';
            return;
        }
        board[i][j] = 'B';

        for (int k = 0; k < 8; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
            dfs(nx, ny);
        }
    };

    int x = click[0], y = click[1];
    if (board[x][y] == 'M') {
        board[x][y] = 'X';
        return board;
    } else dfs(x, y);

    return board;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
