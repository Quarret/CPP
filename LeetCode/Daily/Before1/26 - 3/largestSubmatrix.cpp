#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector sum(m + 1, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) continue;
            sum[i + 1][j] = sum[i][j] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ranges::sort(sum[i], greater());
        for (int j = 0; j < n; j++) {
            ans = max(ans, j * sum[i + 1][j]);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}