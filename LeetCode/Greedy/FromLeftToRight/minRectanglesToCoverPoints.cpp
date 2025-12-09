#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    });
    
    long long ans = 1, x = points[0][0] + w, n = points.size();
    int i = 0;
    while (1) {
        while (i < n && points[i][0] <= x) {
            i++;
        }

        if (i == n) {
            break;
        } else {
            ans++;
            x = 1LL * (points[i][0] + w);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
