/*** 
 * @Author: Quarret
 * @Date: 2025-06-21 21:28:59
 * @LastEditTime: 2025-06-22 11:44:47
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
"E...W..WW",
".E...O...",
"...WO...W",
"..OWW.O..",
".W.WO.W.E",
"O..O.W...",
".OO...W..",
"..EW.WEE."
*/
vector<string> plate = {"E...W..WW",
".E...O...",
"...WO...W",
"..OWW.O..",
".W.WO.W.E",
"O..O.W...",
".OO...W..",
"..EW.WEE."};
vector<vector<int>> ballGame(int num, vector<string>& plate) {
    int n = plate.size(), m = plate[0].size(), flag = 0;
    int next[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

    //由于路径是唯一的，枚举也可以做
    auto dfs = [&](this auto&& dfs, int i, int j, int cnt, int dir) -> void {
        cnt++;
        if (cnt > num) return;
        else if (plate[i][j] == 'O') {
            flag = 1;
            return;
        }

        int nx, ny, nextdir;
        if (plate[i][j] == 'W') {
            nextdir = (dir + 3) % 4;
            nx = i + next[nextdir][0];
            ny = j + next[nextdir][1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
            dfs(nx, ny, cnt, nextdir);
        } else if (plate[i][j] == 'E') {
            nextdir = (dir + 1) % 4;
            nx = i + next[nextdir][0];
            ny = j + next[nextdir][1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
            dfs(nx, ny, cnt, nextdir);
        } else {
            nx = i + next[dir][0];
            ny = j + next[dir][1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
            dfs(nx, ny, cnt, dir);
        }
    };

    //dfs(7, 3, -1, 0);

    vector<vector<int>> ans;

    for (int j = 1; j < m - 1; j++) {
        flag = 0;
        if (plate[0][j] == '.') dfs(0, j, -1, 2);
        if (flag) ans.push_back({0, j});

        flag = 0;
        if (plate[n - 1][j] == '.') dfs(n - 1, j, -1, 0);
        if (flag) ans.push_back({n - 1, j});
    }

    for (int i = 1; i < n - 1; i++) {
        flag = 0;
        if (plate[i][0] == '.') dfs(i, 0, -1, 1);
        if (flag) ans.push_back({i, 0});

        flag = 0;
        if (plate[i][m - 1] == '.') dfs(i, m - 1, -1, 3);
        if (flag) ans.push_back({i, m - 1});
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ballGame(5, plate);

    return 0;
}
