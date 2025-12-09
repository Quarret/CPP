#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                matrix[i][j] += matrix[i - 1][j];
            } 
        }
    }

    // 枚举高度
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ranges::sort(matrix[i], greater());
        for (int j = 0; j < n; j++) {
            ans = max(ans, matrix[i][j] * (j + 1));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
