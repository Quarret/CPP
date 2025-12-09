#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> nums1, nums2;
    for (int i = 0; i < m; i++) {
        nums1.push_back(matrix[i][0]);
        nums2.push_back(matrix[i].back());
    }

    auto check =[&](vector<int>& nums, int x) -> int {
        int l = -1, r = nums.size(), mid = 0;

        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            (nums[mid] >= x ? r : l) = mid;
        }

        return r;
    };

    int arridx1 = check(nums1, target + 1) - 1;
    int arridx2 = check(nums2, target);

    if (arridx2 == m) return false;

    int idx1 = 0, idx2 = 0;
    for (int i = arridx2; i <= arridx1; i++) {
        //idx1 = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
        idx1 = check(matrix[i], target);
        //idx2 = lower_bound(matrix[i].begin(), matrix[i].end(), target + 1) - matrix[i].begin() - 1;
        idx2 = check(matrix[i], target + 1) - 1;

        if (idx2 - idx1 + 1 > 0) return true;
    }

    return false;

}
/*
灵神排除法写法
从右上角开始找，右上角的数据有两个特点比同行所有数大比同列所有数小
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;

    while (i < m && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] > target) j--; //同列下面的数都大于target
        else i++; // 同行左边的数都小于target
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
