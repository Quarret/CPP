#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int search(vector<int>& nums, int target) {
    auto findmin = [&]() {
        int l = -1, r = nums.size(), mid = 0;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            (nums[mid] <= nums.back() ? r : l) = mid;
        }

        return r;
    };
    
    int i = findmin();
    if (target <= nums.back()) {
        int idx1 = lower_bound(nums.begin() + i, nums.end(), target) - nums.begin();
        if (idx1 == nums.size()) return -1;
        return nums[idx1] == target ? idx1 : -1;
    }  else {
        int idx2 = lower_bound(nums.begin(), nums.begin() + i, target) - nums.begin();
        if (idx2 == nums.size()) return -1;
        return nums[idx2] == target ? idx2 : -1;
    }
}

int search(vector<int>& nums, int target) {
    int last = nums.back();
    // check 判断 target 在 x 或 target == x 的情况
    auto check = [&](int i) -> bool {
        int x = nums[i];
        if (x > last) { // x 在第一段
            return x >= target && target > last;
        }
        // x 在第二段
        // target 在第一段或 target 比 x 小在第二段
        return target > last || target <= x;
    };

    int l = -1, r = nums.size(), mid = 0;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return nums[r] == target ? r : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
