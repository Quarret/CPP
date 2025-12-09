#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
灵神思路:
去掉与mid相同的数组末尾
若end为最小值，数字中还有nums[mid],最小值存在
若end不为最小值，去除一个错误答案
*/  
int findMin(vector<int>& nums) {
    int n = nums.size();
     //由于最后一个数确定在最小值的右侧，无需放入二分范围内，二分范围只放未确定左右的数
    int l = -1, r = n - 1, mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == nums[r]) r--;
        else if (nums[mid] < nums[r]) r = mid;//由于nums[mid] < nums[r]所以现在它被更新为新数组的最右侧，无需加入二分区间
        else l = mid;
    }

    return nums[r];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
