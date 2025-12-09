#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle.back().size();
    vector f(m + 1, vector<int>(n + 1, INT_MAX));

    f[0][0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            f[i + 1][j + 1] = min(f[i][j], f[i][j + 1]) + triangle[i][j];
        }
    }

    return *min_element(f[m].begin() + 1, f[m].end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    

    return 0;
}
