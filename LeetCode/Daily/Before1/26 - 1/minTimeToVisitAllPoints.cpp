#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int x0 = points[i - 1][0], y0 = points[i - 1][1];
        int x1 = points[i][0], y1 = points[i][1];
        int delta_x = abs(x0 - x1);
        int delta_y = abs(y0 - y1);
        int mn = min(delta_x, delta_y);
        ans += mn + (delta_x - mn) + (delta_y - mn);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}