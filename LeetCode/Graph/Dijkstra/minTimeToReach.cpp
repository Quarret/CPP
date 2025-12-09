#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size(), m = moveTime[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

    auto cmp = [&](tuple<int, int, int> &t1, tuple<int, int, int> &t2) -> bool {
        auto [x, y, v1] = t1;
        auto [a, b, v2] = t2;
        return v1 > v2;
    };

    vector dis(n, vector<long long>(m, INT64_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
    dis[0][0] = 0;
    pq.emplace(0, 0, 0);
    
    while (!pq.empty()) {
        auto [x, y, s] = pq.top();
        pq.pop();

        if (s > dis[x][y]) continue;

        for (auto &[dx, dy] : next) {
            int nx = x + dx, ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int ns = s + 1 > moveTime[nx][ny] ? s + 1 : moveTime[nx][ny] + 1;
            if (ns < dis[nx][ny]) {
                dis[nx][ny] = ns;
                pq.emplace(nx, ny, ns);
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
