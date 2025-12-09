#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    int n = grid.size(), m = grid[0].size();     
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pq.emplace(grid[i][j], i);
        }
    }

    long long ans = 0;
    vector<int> cnt(n, 0);
    while (k) {
        auto [val, row] = pq.top();
        pq.pop();

        if (cnt[row] == limits[row]) continue;
        ans += 1LL * val;
        cnt[row]++;
        k--;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
