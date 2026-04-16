#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 检查是否存在一对 (i,j) 使得 min(Ai+Aj, Bi+Bj) >= target*2
bool check(ll target, int n, const vector<int>& a, const vector<int>& b) {
    // 需要 Ai + Aj >= target 且 Bi + Bj >= target
    // 即 Aj >= target - Ai 且 Bj >= target - Bi
    // 对于每个 i，需要找 j 满足：Aj >= target - Ai 且 Bj >= target - Bi

    // 按 A 排序后，对于每个 i，需要找 A 足够大且 B 也足够大的 j
    // 可以预处理后缀 B 的最大值

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {a[i], b[i]};
    }
    sort(arr.begin(), arr.end());

    // suffixMax[i] = max(b[i], b[i+1], ..., b[n-1]) after sorting by a
    vector<int> suffixMax(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        suffixMax[i] = max(arr[i].second, suffixMax[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        ll needA = target - arr[i].first;
        ll needB = target - arr[i].second;

        // 找第一个 A >= needA 的位置
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid].first >= needA) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // lo 是第一个 A >= needA 的位置
        if (lo < n && suffixMax[lo] >= needB) {
            return true;
        }
    }

    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // 二分答案，答案范围 [0, 2e8]
    // 最终答案是 (max min(Ai+Aj, Bi+Bj)) / 2
    // 二分的是 2*ans，即 min(Ai+Aj, Bi+Bj) 的最大值

    ll lo = 0, hi = 2e8 + 2e8; // 最大可能的和
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (check(mid, n, a, b)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    // 输出保留一位小数
    cout << fixed << setprecision(1) << lo / 2.0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}