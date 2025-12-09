#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumRows(vector<vector<int>>& matrix, int numSelect) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = 0;
    for (int k = 0; k < (1 << n); k++) {
        if (__builtin_popcount(k) != numSelect) continue;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int ok = 1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 1) continue;
                if ((k & (1 << j)) != (1 << j)) {
                    ok = 0;
                }
            }
            cnt += ok;
        }
        ans = max(ans, cnt);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
