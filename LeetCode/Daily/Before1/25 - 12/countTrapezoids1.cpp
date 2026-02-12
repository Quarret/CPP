#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    unordered_map<double, map<double, int>> cnt1; // 斜率 -> 截距 -> 个数    
    unordered_map<int, map<double, int>> cnt2; // 中点 -> 斜率 -> 个数
    
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int x = points[i][0], y = points[i][1];
        for (int j = 0; j < i; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            int dx = x - x2;
            int dy = y - y2;
            double k = dx ? 1.0 * dy / dx : DBL_MAX;
            double d = dx ? 1.0 * (y * dx - x * dy) / dx : x;
            cnt1[k][d]++;
            int mid = (x + x2 + 2000) << 16 | (y + y2 + 2000);
            cnt2[mid][k]++;
        }
    }

    int ans = 0;
    for (auto [_, m] : cnt1) {
        int s = 0;
        for (auto [_, c] : m) {
            ans += s * c;
            s += c;
        }
    }

    for (auto [_, m] : cnt2) {
        int s = 0;
        for (auto [_, c] : m) {
            ans -= s * c;
            s += c;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
