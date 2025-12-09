#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size(), m = moveTime[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    vector dis(n, vector<int>(m, INT32_MAX));
    struct node {
        int s;
        int x;
        int y;
        int cnt;
    };
    auto cmp = [&](node &a, node &b) -> bool {
        return a.s > b.s;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    dis[0][0] = 0;
    pq.emplace(0, 0, 0, 0);

    while (!pq.empty()) {
        auto [s, x, y, cnt] = pq.top();
        pq.pop();

        if (s > dis[x][y]) continue;

        for (auto &[dx, dy] : next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int ns = (s < moveTime[nx][ny] ? moveTime[nx][ny] : s) + (cnt % 2) + 1;//(x + y) % 2 + 1
            if (ns < dis[nx][ny]) {
                dis[nx][ny] = ns;
                pq.emplace(ns, nx, ny, cnt ^ 1);
            }  
        }
    }

    return dis[n - 1][m - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
