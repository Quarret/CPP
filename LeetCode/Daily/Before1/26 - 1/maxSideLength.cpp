#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    using ll = long long;
    int m = mat.size(), n = mat[0].size();
    int mn = min(m, n);

    vector sum(m + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
        }
    }

    auto check = [&](int x) -> bool {
        for (int i = 0; i <= m - x; i++) {
            for (int j = 0; j <= n - x; j++) {
                int x1 = i, y1 = j;
                int x2 = i + x - 1, y2 = j + x - 1;
                ll s = sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
                if (s <= threshold) return true;
            }
        }

        return false;
    };


    int left = 0, right = mn + 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(mid) ? left : right) = mid;
    }

    return left;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}