#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int m = rowCosts.size(), n = colCosts.size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    
    queue<array<int, 3>> q;
    vector dis(m, vector<int>(n, INT_MAX / 2));
    q.push({startPos[0], startPos[1], 0});
    dis[startPos[0]][startPos[1]] = 0;

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        if (x == homePos[0] && y == homePos[1]) {
            break;
        }

        for (int i = 0; i < 2; i++) {
            int nx = x + nxt[i][0];
            int ny = y;
            
            if (nx < 0 || nx >= m) continue;
            int new_dis = d + rowCosts[nx];
            if (new_dis < dis[nx][ny]) {
                dis[nx][ny] = new_dis;
                q.push({nx, ny, new_dis});
            }
        }
        
        for (int i = 2; i < 4; i++) {
            int nx = x;
            int ny = y + nxt[i][1];
            
            if (ny < 0 || ny >= n) continue;
            int new_dis = d + colCosts[ny];
            if (new_dis < dis[nx][ny]) {
                dis[nx][ny] = new_dis;
                q.push({nx, ny, new_dis});
            }
        }
    }

    return dis[homePos[0]][homePos[1]];
}

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int start_x = startPos[0], start_y = startPos[1];        
    int end_x = homePos[0], end_y = homePos[1];
    int m = rowCosts.size(), n = colCosts.size();

    vector pre_row(m + 1, 0);
    vector pre_col(n + 1, 0);
    for (int i = 0; i < m; i++) pre_row[i + 1] = pre_row[i] + rowCosts[i];
    for (int i = 0; i < n; i++) pre_col[i + 1] = pre_col[i] + colCosts[i];

    int ans = 0;
    ans += start_x <= end_x ? pre_row[end_x + 1] - pre_row[start_x + 1] : pre_row[start_x] - pre_row[end_x];
    ans += start_y <= end_y ? pre_col[end_y + 1] - pre_col[start_y + 1] : pre_col[start_y] - pre_col[end_y];
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}