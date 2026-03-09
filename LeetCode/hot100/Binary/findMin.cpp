#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findMin(vector<int>& nums) {
    int l = -1, r = nums.size(), mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        // nums[mid] <= nums.back() 时, 最小值在当前 mid 左侧, 保证 r 始终在最小值小标 i 右侧
        (nums[mid] <= nums.back() ? r : l) = mid;
    }

    return nums[r];
}

// 错误
int findMin(vector<int>& nums) {
    int l = -1, r = nums.size(), mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (nums[mid] >= nums.back() ? l : r) = mid;
    }

    return nums[l];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}