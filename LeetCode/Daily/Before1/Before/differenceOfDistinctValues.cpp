#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector mat(m, vector<int>(n, 0));

    for (int k = -(m - 1); k <= (n - 1); k++) {
        int min_j = max(0, k);
        int max_j = min(n - 1, k + m - 1);

        // unordered_set<int> st;
        unsigned long long st = 0;
        for (int j = max_j; j >= min_j; j--) {
            // mat[j - k][j] = st.size();
            // st.insert(grid[j - k][j]);
            mat[j - k][j] = __builtin_popcount(st);
            st |= (1ULL << grid[j - k][j]);
        }

        // st.clear();
        for (int j = min_j; j <= max_j; j++) {
            // mat[j - k][j] = abs((int)st.size() - mat[j - k][j]);
            // st.insert(grid[j - k][j]);
            mat[j - k][j] = abs(mat[j - k][j] - __builtin_popcount(st));
            st |= (1ULL << grid[j - k][j]);
        }
    }

    return mat;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
