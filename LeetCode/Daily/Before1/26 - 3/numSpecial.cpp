#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> row(m), col(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            row[i] += mat[i][j];
            col[j] += mat[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) continue;
            if (row[i] == 1 && col[j] == 1) ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}