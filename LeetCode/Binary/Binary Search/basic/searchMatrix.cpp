#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> nums;
    for (int i = 0; i < m; i++) {
        nums.push_back(matrix[i][0]);
        nums.push_back(matrix[i].back());
    }

    int arridx = (lower_bound(nums.begin(), nums.end(), target) - nums.begin()) / 2;
    int idx1 = lower_bound(matrix[arridx].begin(), matrix[arridx].end(), target) - matrix[arridx].begin();
    int idx2 = lower_bound(matrix[arridx].begin(), matrix[arridx].end(), target + 1) - matrix[arridx].begin() - 1;

    if (idx2 - idx1 > 0) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
