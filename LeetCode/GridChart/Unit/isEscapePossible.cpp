/*** 
 * @Author: Quarret
 * @Date: 2025-07-01 17:03:15
 * @LastEditTime: 2025-07-02 16:39:33
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    unordered_map<long long, int> vis;
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    for (auto& arr: blocked) vis[arr[0] * 1e9 + arr[1]] = 1;
    
    queue<pair<int, int>> q;
    q.emplace(source[0], source[1]);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= 1e6 || ny < 0 || ny >= 1e6 || vis[nx * 1e9 + ny]) continue;
            if (nx == target[0] && ny == target[1]) return true;
            vis[nx * 1e9 + ny] = 1;
            q.emplace(nx, ny);
        }
    }

    return false;
}

bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    unordered_map<long long, int> vis;
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    for (auto& arr: blocked) vis[arr[0] * 1e6 + arr[1]] = 1;

    auto dfs = [&](this auto& dfs, int x, int y) -> bool {
        vis[x * 1e6 + y] = 1;
        if (x == target[0] && y == target[1]) return true;
        
        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= 1e6 || ny < 0 || ny >= 1e6 || vis[nx * 1e6 + ny]) continue;
            dfs(nx, ny);
        }
    };

    dfs(source[0], source[1]);
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
