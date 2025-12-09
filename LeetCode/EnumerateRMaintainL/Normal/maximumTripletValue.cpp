/*** 
 * @Author: Quarret
 * @Date: 2025-05-08 19:34:01
 * @LastEditTime: 2025-06-04 16:23:24
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;
    int maxidx = 0, i = 0, j = 1, num = nums[0] - nums[1];
    if (nums[1] > nums[0]) maxidx = 1;

    for (int k = 2; k < n; k++) {
        if (maxidx < k - 1 && nums[maxidx] - nums[k - 1] > num) {
            i = maxidx;
            j = k - 1;
            num = nums[i] - nums[j];
        }
        ans = max(ans, num * (long long)nums[k]);

        if (nums[k - 1] > nums[maxidx]) maxidx = k - 1;
    }

    return max(ans, (long long)0);
}
/*
灵神枚举k做法
遍历时
维护最大nums[i] = premax
维护最大maxdiff = premax - nums[j]
计算最大结果ans = maxdiff * nums[k]

顺序不能改变
ans需要maxdiff, maxdiff需要premax

一点启示:
在遍历中，当彼此相互关联的变量
关联参数越大的量写在前，越小越后
换一种说法
更新越后的量写在前，越早的写在后
*/
long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0;
    int premax = 0, maxdiff = 0;
    for (int x : nums) {//{-1(i), -1(j), 0(k), 1, 2, 3}
        ans = max(ans, 1LL * maxdiff * x);//k最大
        maxdiff = max(maxdiff, premax - x);//j居中
        premax = max(premax, x);//i最小
    }

    return ans;
}

/*
枚举j做法(最容易理解的做法)
根据答案式可知：需要nums[i],nums[j]越大答案越大,维护j的前后缀最大值数组
*/
long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;

    vector<int> pre(n, 0), suf(n, 0);
    pre[0] = nums[0], suf[0] = nums.back();
    for (int i = 1; i < n; i++) pre[i] = max(nums[i], pre[i - 1]);//计算前缀过程可放入j循环中
    for (int i = n - 2; i >= 0; i--) suf[i] = max(nums[i], suf[i + 1]);
    
    for (int j = 1; j < n - 1; j++) {
        ans = max(ans, 1LL * (pre[j - 1] - nums[j]) * suf[j + 1]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
