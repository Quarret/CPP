#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maxPoints(vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    vector f(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < n; t++) {
                f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][t + 1] - abs(t - j) + points[i][j]);
            }
        }
    }

    return *max_element(f[m].begin() + 1, f[m].end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
