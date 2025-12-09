#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
check函数第二次的思路和题解差不多，但没写出来
最近写check函数的逻辑都会紊乱，一定要静心写下来
*/
int maxValue(int n, int index, int maxSum) {
    long long l = 1, r = maxSum - (n - 1) + 1, mid = 0;

    auto sum = [&](long long k, long long cnt) {
        return k >= cnt ? (k + k - cnt + 1) * cnt / 2 : (k + 1) * k / 2 + cnt - k;
        // 1 2 3 4 3 2 1 1
    };

    auto check = [&](long long mid) -> bool {
        return sum(mid - 1, index) + sum(mid, n - index) <= maxSum;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
