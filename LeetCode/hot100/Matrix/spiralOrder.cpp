#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int next[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    vector vis(m, vector<int>(n, 0));
    vector<int> ans;

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    vis[0][0] = 1;
    

    while (!q.empty()) {
        auto [x, y, dir] = q.front();
        q.pop();

        vis[x][y] = 1;
        ans.push_back(matrix[x][y]);

        int nx = x + next[dir][0];
        int ny = y + next[dir][1];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) dir = (dir + 1) % 4;
        nx = x + next[dir][0];
        ny = y + next[dir][1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;

        q.emplace(nx, ny, dir);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
