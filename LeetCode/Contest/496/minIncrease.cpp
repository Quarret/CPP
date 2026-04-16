#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 前后缀分解
// 赛时将偶数长度的情况想错, 偶数长度可以像奇数那样隔一个峰值, 或最多隔 2 个峰值
long long minIncrease(vector<int>& nums) {
    using ll = long long;
    int n = nums.size();
    vector<ll> suf(n + 1);
    for (int i = n - 2; i > 0; i -= 2) {
        suf[i] = suf[i + 2] + max(max(nums[i - 1], nums[i + 1]) - nums[i] + 1, 0);
    }

    // 奇数长度峰值个数选法唯一
    if (n % 2) {
        return suf[1];
    }

    // 枚举这两个空格的位置
    ll ans = suf[2]; // 开头隔两个
    ll pre = 0;
    for (int i = 1; i < n - 1; i += 2) {
        pre += max(max(nums[i - 1], nums[i + 1]) - nums[i] + 1, 0);
        ans = min(ans, pre + suf[i + 3]); // 隔两个
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}