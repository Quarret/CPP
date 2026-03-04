#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int l = -1, r = matrix.size(), mid = 0;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (matrix[mid][0] <= target) l = mid;
        else r = mid;
    }

    if (l == -1) return false;
    int idx = lower_bound(matrix[l].begin(), matrix[l].end(), target + 1) - matrix[l].begin() - 1;

    return target == matrix[l][idx];
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;

    while (i < m && j >= 0) {
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] > target) j--;
        else i++;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
