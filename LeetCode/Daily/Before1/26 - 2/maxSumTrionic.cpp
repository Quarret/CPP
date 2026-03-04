#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 分组循环
long long maxSumTrionic(vector<int>& nums) {
    using ll = long long;
    int n = nums.size();
    ll ans = LLONG_MIN;

    int i = 0;
    while (i < n) {
        // 第一段
        int start = i++;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        if (i == start + 1) continue;

        // 第二段
        int peak = i - 1;
        ll res = nums[peak - 1] + nums[peak]; // 第一段必须要有两个数字
        while (i < n && nums[i - 1] > nums[i]) { // 中间段的数字必须都要加入 res
            res += nums[i];
            i++;
        }
        if (i == peak + 1 || i == n || nums[i - 1] == nums[i]) continue;

        // 第三段
        int bottom = i - 1;
        res += nums[i++]; // 第三段必须有两个数字, bottom 以及在第二段加入 res 中了
        ll max_s = 0, s = 0;
        while (i < n && nums[i - 1] < nums[i]) {
            s += nums[i];
            max_s = max(max_s, s);
            i++;
        }
        res += max_s;

        // 第一段紧挨 peak 的区间和最大值
        max_s = s = 0;
        for (int j = peak - 2; j >= start; j--) {
            s += nums[j];
            max_s = max(max_s, s);
        }
        res += max_s;
        ans = max(ans, res);

        i = bottom; // 前一个三段式数组的 bottom 是下一个三段式的 start
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}