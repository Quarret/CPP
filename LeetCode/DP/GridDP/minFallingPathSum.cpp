#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector f(n + 2, vector<int>(n + 2, INT32_MAX));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                f[i + 1][j + 1] = matrix[i][j];
                continue;
            }
            f[i + 1][j + 1] = min({f[i][j], f[i][j + 1], f[i][j + 2]}) + matrix[i][j];
        }
    }
    
    return *min_element(f[n].begin() + 1, f[n].end() - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
