#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            for (int k = j + 1; k < n; k++) {
                int x3 = points[k][0], y3 = points[k][1];
                double s = abs(1.0 * x1 * (y2 - y3) + 1.0 * x2 * (y3 - y1) + 1.0 * x3 * (y1 - y2)) / 2;
                ans = max(ans, s);
            }
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
