#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> nums;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nums.push_back(grid[i][j]);
        }
    }
    
    int k = m * n;
    ranges::sort(nums);

    int ans = 0, median = nums[k / 2];
    for (int y : nums) {
        int diff = abs(y - median);
        if (diff % x) return -1;
        ans += diff / x;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
