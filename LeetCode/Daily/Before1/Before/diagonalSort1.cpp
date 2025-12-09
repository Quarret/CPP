#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    
    for (int k = -(m - 1); k <= n - 1; k++) {
        int min_j = max(0, k);
        int max_j = min(n - 1, k + m - 1);

        vector<int> a;
        for (int j = min_j; j <= max_j; j++) {
            a.push_back(mat[j - k][j]);
        }
        sort(a.begin(), a.end());

        for (int j = min_j, t = 0; j <= max_j; j++) {
            mat[j - k][j] = a[t++];
        }
    }

    return mat;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
