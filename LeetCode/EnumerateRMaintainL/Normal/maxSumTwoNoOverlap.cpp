/*** 
 * @Author: Quarret
 * @Date: 2025-05-09 19:43:41
 * @LastEditTime: 2025-06-04 16:25:06
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {0,6,5,2,2,5,1,9,4};
/*
枚举两数组中间值，统计两边的最大值
*/
int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> firstpre(n, 0), firstsuf(n, 0), secondpre(n, 0), secondsuf(n, 0);


    auto pre = [&](int len, vector<int>& arr) -> void {
        int num = 0;
        for (int i = 0; i < n; i++) {
            num += nums[i];

            if (i < len - 1) continue;

            if (i == 0) arr[i] = num;
            else arr[i] = max(num, arr[i - 1]);

            num -= nums[i - len + 1];
        }
    };

    pre(firstLen, firstpre);
    pre(secondLen, secondpre);

    /*
    后缀的计算可以用前缀替代
    suf[j] = pre[n - 1] - pre[j - 1]
    */
    auto suf = [&](int len, vector<int>& arr) -> void {
        int num = 0;
        for (int i = n - 1; i >= 0; i--) {
            num += nums[i];

            if (i > n - len) continue;

            if (i == n - 1) arr[i] = num;
            else arr[i] = max(num, arr[i + 1]);
            num -= nums[i + len - 1];
        }
    };

    suf(firstLen, firstsuf);
    suf(secondLen, secondsuf);

    int ans = 0;
    for (int i = firstLen - 1; i <= n - secondLen - 1; i++) {
        ans = max(ans, firstpre[i] + secondsuf[i + 1]);
    }

    for (int i = secondLen - 1; i <= n - firstLen - 1; i++) {
        ans = max(ans, secondpre[i] + firstsuf[i + 1]);
    }
    return ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxSumTwoNoOverlap(nums, 1, 2);

    return 0;
}
