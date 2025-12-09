/*** 
 * @Author: Quarret
 * @Date: 2025-04-15 23:41:10
 * @LastEditTime: 2025-06-06 00:02:10
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*
闭区间二分查找
原函数意义: 
第一个大于等于target的位置 -> check(target)
第一个大于target的位置 -> check(target + 1)
最后一个小于等于target的位置 -> check(target + 1) - 1
最后小于target的位置 -> check(target) - 1
*/
int check(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int mid;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int num1 = check(nums, target), num2 = check(nums, target + 1);
    
    if (num1 == nums.size() || nums[num1] != target) return {-1, -1};
    return {num1, num2 - 1};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
