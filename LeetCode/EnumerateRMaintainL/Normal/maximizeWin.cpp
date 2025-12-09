/*** 
 * @Author: Quarret
 * @Date: 2025-05-10 22:08:26
 * @LastEditTime: 2025-06-04 16:29:41
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
灵神思路:
首先考虑一段线段能够包含的点的数量
nums[r] - nums[l] <= k
明显越小越合理,所以答案为 r - l + 1

再来考虑两端
贪心的想，两个线段不重合能够覆盖的点的数量最多
现在问题在如何求第一条线段的最大值

动态规划:
mx[i + 1]代表右端点小于等于i的线段涵盖点的最大值
当第一条线段右端点nums[i]上时，可以覆盖最多的是 r1 - l1 + 1(l1, r1分别是第一段的做右端点)
当右端点小于nums[i]时，等价于求右端点小于等于nums[i - 1],

第二条线段 = r - l + 1
第一条线段 = <= nums[l - 1] = mx[l]

在计算第二条线段覆盖值时，可以同步更新第一条线段的最大值
例如当第一条线段的右端点小于等于r时
mx[r + 1] = max(mx[r], r - l + 1)
*/
int maximizeWin(vector<int>& prizePositions, int k) {
    int n = prizePositions.size();

    if (prizePositions.back() - prizePositions[0] <= 2 * k + 1) return n;

    int ans = 0, l = 0;
    vector<int> mx(n + 1, 0);
    for (int r = 0; r < n; r++) {
        while (prizePositions[r] - prizePositions[l] > k) {
            l++;
        }

        ans = max(ans, mx[l] + r - l + 1);
        mx[r + 1] = max(mx[r], r - l + 1);
    }

    return ans;
}

/*
两线段问题枚举线段中间值
枚举两条线段中间值mid   
*/
int maximizeWin(vector<int>& prizePositions, int k) {
    int n = prizePositions.size();

    if (prizePositions.back() - prizePositions[0] <= 2 * k + 1) return n;

    int ans = 0, l = 0, r = 0, mx = 0;
    for (int mid = 0; mid < n; mid++) {
        // mid作为第二条线段的左端点
        while (r < n && prizePositions[r] - prizePositions[mid] <= k) r++;
        ans = max(ans, mx + r - mid);
        
        // mid作为第一条线段的右端点
        // 先跑右线段再跑左线段避免重复计算两次mid值
        while (prizePositions[mid] - prizePositions[l] > k) l++;
        mx = max(mx, mid - l);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}
