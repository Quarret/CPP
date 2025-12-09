#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int dir[2][2] = {-1, 1, 1, -1};
    int d = 0, i = 0, j = 0, m = mat.size(), n = mat[0].size();
    vector<int> ans;
    
    while (1) {
        ans.push_back(mat[i][j]);
        if (i == m - 1 && j == n - 1) break;

        if (d == 0) {
            if (i == 0 || j == n - 1) {
                if (j < n - 1) j += 1;
                else i += 1;
                d = 1;    
            } else {
                i += dir[d][0];
                j += dir[d][1];
            }
        } else {
            if (j == 0 || i == m - 1) {
                if (i < m - 1) i += 1;
                else j += 1;
                d = 0;
            } else {
                i += dir[d][0];
                j += dir[d][1];
            }
        }
    }

    return ans;
}


vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> ans;

    for (int k = 0; k < m + n - 1; k++) {
        int min_j = max(0, k - (m - 1));
        int max_j = min(n - 1, k);
        if (k % 2 == 0) {//直线和为偶数，从左往右
            for (int j = min_j; j <= max_j; j++) {
                ans.push_back(mat[k - j][j]);
            }
        } else {
            for (int j = max_j; j >= min_j; j--) {
                ans.push_back(mat[k - j][j]);
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
