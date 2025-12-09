#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector sum(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] + matrix[i][j] - sum[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int l = -1, r = min(m - i, n - j), mid = 0;
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                if (sum[i + mid + 1][j + mid + 1] - sum[i + mid + 1][j] - sum[i][j + mid + 1] + sum[i][j] == (mid + 1) * (mid + 1)) l = mid;
                else r = mid;
            }
            ans += l + 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
