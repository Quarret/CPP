#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算数字 n 中包含因子 p 的个数
int countFactor(long long n, int p) {
    int cnt = 0;
    while (n > 0 && n % p == 0) {
        cnt++;
        n /= p;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n + 1);
    vector<int> cnt2(n + 1), cnt5(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt2[i] = countFactor(a[i], 2);
        cnt5[i] = countFactor(a[i], 5);
    }

    // 前缀和
    vector<long long> pre2(n + 2, 0), pre5(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pre2[i] = pre2[i - 1] + cnt2[i];
        pre5[i] = pre5[i - 1] + cnt5[i];
    }

    long long total2 = pre2[n];
    long long total5 = pre5[n];

    long long ans = 0;

    for (int l = 1; l <= n; l++) {
        long long maxDel2 = total2 - k;  // 最多能删除的 2
        long long maxDel5 = total5 - k;  // 最多能删除的 5

        if (maxDel2 < 0 || maxDel5 < 0) {
            cout << 0 << endl;
            return 0;
        }

        long long base2 = pre2[l - 1];
        long long base5 = pre5[l - 1];

        // 二分找最大的 r，check: 删除 [l, mid] 后剩余因子 >= k
        int lo = l, hi = n, r = l - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long del2 = pre2[mid] - base2;
            long long del5 = pre5[mid] - base5;
            long long remain2 = total2 - del2;
            long long remain5 = total5 - del5;
            if (min(remain2, remain5) >= k) {
                r = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (r >= l) {
            ans += (r - l + 1);
        }
    }

    cout << ans << endl;

    return 0;
}
