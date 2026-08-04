#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    // 0:E, 1:S, 2:W, 3:N (顺时针)
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, -1, 0, 1};

    set<pair<int, int>> block;
    for (auto &obstacle : obstacles) {
        block.insert({obstacle[0], obstacle[1]});
    }

    int dir = 3; // 初始朝北
    int x = 0, y = 0;
    ll ans = 0;

    for (int cmd : commands) {
        if (cmd > 0) {
            for (int i = 0; i < cmd; i++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (block.count({nx, ny})) break;
                x = nx;
                y = ny;
            }
            ans = max(ans, 1LL * x * x + 1LL * y * y);
        } else if (cmd == -2) {
            dir = (dir + 3) % 4; // 左转
        } else {
            dir = (dir + 1) % 4; // 右转
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}