#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDistance(int side, vector<vector<int>>& points, int k) {
    int n = points.size();
    long long l = 0, r = 2 * side + 1, mid = 0;
    sort(points.begin(), points.end(), [&](vector<int> point1, vector<int> point2) {
        if (point1[0] == point2[0]) return point1[1] < point2[1];
        return point1[0] < point2[0];
    });
    
    auto check = [&](long long t) -> bool {
        long long cnt = 1, dis = 0, x = points[0][0], y = points[0][1];
        for (int i = 1; i < n; i++) {
            dis = abs(points[i][0] - x) + abs(points[i][1] - y);
            if (dis >= t) cnt++;
            x = points[i][0];
            y = points[i][1];

            if (cnt >= k) return 1;
        }

        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
