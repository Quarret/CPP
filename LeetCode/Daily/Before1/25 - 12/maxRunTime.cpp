#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxRunTime(int n, vector<int>& batteries) {
    long long tot = accumulate(batteries.begin(), batteries.end(), 0LL);
    long long l = 0, r = tot + 1;
    while (l + 1 < r) {
        long long mid = l + (r - l) / 2;
        long long s = 0;
        for (long long x : batteries) {
            s += min(x, mid);
        }
        // 对于时间 x, 当 n * x <= s 则一定存在分配方法
        // 即大于 x 的只为一台电脑服务, 小于的多个一起供给一台电脑 (分为两段 前 / 后)
        (1LL * n * mid <= s ? l : r) = mid;
    }

    return l;
}

long long maxRunTime(int n, vector<int>& batteries) {
    ranges::sort(batteries, greater());
    long long tot = accumulate(batteries.begin(), batteries.end(), 0LL);

    for (int i = 0; ; i++) {
        // 小于 x = tot / 的电池
        // 即后续 n * x <= tot, 按上二分可知答案
        if (batteries[i] <= tot / n) {
            return tot / n;
        }

        // 大于 x 的电池, 只为一个电脑服务
        // 问题规模缩减为 n - 1
        tot -= batteries[i];
        n--;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
