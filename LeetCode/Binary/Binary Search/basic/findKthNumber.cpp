#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
MLE
*/
int findKthNumber(int m, int n, int k) {
    vector<long long> nums;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            nums.push_back(i * j);
        }
    }
    sort(nums.begin(), nums.end());
    long long l = 0, r = *max_element(nums.begin(), nums.end()) + 1, mid = 0;

    auto check = [&](long long t) -> bool {
        long long idx = lower_bound(nums.begin(), nums.end(), t + 1) - nums.begin() - 1;
        if (idx >= k - 1) return 1;
        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}

/*
灵神写法
不用开数组,不必建立乘法表数组来lowerbound找
计算每个x下比他小的数目，大于等于k return 1
*/
int findKthNumber(int m, int n, int k) {
    long long l = 0, r = m * n + 1, mid = 0;

    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(x / i, n);
            if (cnt >= k) return 1;
        }

        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
