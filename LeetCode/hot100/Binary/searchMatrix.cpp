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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
