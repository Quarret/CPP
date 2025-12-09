#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
两次二分
*/
int search1(vector<int>& nums, int target) {
    int n = nums.size();
    int l = -1, r = n, mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (nums[mid] < nums.back() ? r : l) = mid;
    }
    int idx = r;

    if (target > nums.back()) {
        int idx1 = lower_bound(nums.begin(), nums.begin() + idx, target) - nums.begin();
        return (nums[idx1] == target ? idx1 : -1);
    } else {
        int idx2 = lower_bound(nums.begin() + idx, nums.end(), target) - nums.begin();
        return (nums[idx2] == target ? idx2 : -1);
    }
}

/*
一次二分
灵神思路:
先讨论nums[mid] = x 在target的右边情况
如果x > nums[n - 1], mid 在第一段，target也一定在第一段， 且x >= target
target > nums[n - 1] && x >= target
如果x <= nums[n - 1], mid 在第二段，target两端皆可
如果target在第一段，mid在target右侧
如果target在第二段 x >= target
target <= nums[n - 1] || x >= target
此时可以缩小r到mid的位置
*/

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = -1, r = n, mid = 0;

    auto check = [&](int x) -> bool {
        if (nums[x] > nums[r]) return target > nums[r] && nums[x] >= target;
        return target > nums[r] || nums[x] >= target;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return (nums[r] == target ? r : -1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {4,5,6,7,0,1,2};

    return 0;
}
