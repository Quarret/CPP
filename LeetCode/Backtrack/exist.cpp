#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size(), t = word.size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int x, int y, int idx) -> bool {
        if (board[x][y] != word[idx]) {
            return false;
        }

        if (idx == t - 1) {
            return true;
        }

        char c = board[x][y];
        board[x][y] = ' ';
        for (auto [dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0  || nx >= m || ny < 0 || ny >= n || board[nx][ny] == ' ') continue;
            if (dfs(nx, ny, idx + 1)) {
                return true;
            }
        }
        board[x][y] = c;
        
        return false;
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0] && dfs(i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
