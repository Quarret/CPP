#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfPairs(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(), points.end(), [&](auto &a, auto & b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int y1 = points[i][1];
        int max_y = INT_MIN;
        for (int j = i + 1; j < n && max_y < y1; j++) {
            int y2 = points[j][1];
            if (y2 <= y1 && y2 > max_y) {
                max_y = y2;
                ans++;
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
