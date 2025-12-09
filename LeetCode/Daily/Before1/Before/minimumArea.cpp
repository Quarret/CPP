#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumArea(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int left = 1e9, right = -1, top = 1e9, bottom = -1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        }
    }

    return (right - left + 1) * (bottom - top + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
