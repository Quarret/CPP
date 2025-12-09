#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
旋转排序数组 -> 局部有序性
二分的精髓是 根据特定条件，减小搜索范围!!!
灵神思路：二分缩小范围，根据最后一个值来判断mid在那一段来决定收缩那侧
若nums[mid] <= nums[n - 1],mid一定在第二段 mid右侧的数据都大于minn, 收缩 r = mid
若nums[mid] > nums[n - 1], mid 一定在第一段， mid左侧的数据都大于minn，收缩 l = mid
若等于

在一端递增中，同理可得
*/
int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = -1, r = n - 1, mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (nums[mid] < nums.back() ? r : l) = mid; 
    }

    return nums[r];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
