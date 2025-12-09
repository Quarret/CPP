#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
峰谷数组 -> 局部有序性
灵神思路:
红蓝染色法 -- 峰左侧染红，右侧蓝，数组最右侧数字绝对为蓝
峰左侧递增，右侧递减
当查找到某个数字大于右侧数字时，它为蓝色，现在右侧的都是蓝色，收缩右区间 r = mid
峰值是第一个蓝色或最后一个红色 == l + 1 == r
我的二分写法是找寻第一个bool值为1的编号，所以return r
*/
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    long long l = -1, r = n - 1, mid = 0;

    auto check = [&](long long x) -> bool {
        return nums[x] > nums[x + 1];
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
