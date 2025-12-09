#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    auto check = [&](int row, int l, int r) -> int {
        int mid = 0;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            (mat[row][mid] > mat[row][mid + 1] ? r : l) = mid;
        }

        return r;
    };
    
    for (int i = 0; i < m; i++) {
        int idx = check(i, 0, n - 1), cnt = 0;  

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
