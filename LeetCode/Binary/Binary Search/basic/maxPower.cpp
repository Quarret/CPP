#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1,2,4,5,0};
long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    long long left = 0, mid = 0, right = 0;
    for (int i = 0; i < n; i++) right += stations[i];
    right++;

    auto check = [&](long long t) -> bool {
        long long sum = 0, cnt = 0, l1 = -r;
        vector<int> tmp(stations.begin(), stations.end());
        for (int r1 = -r; r1 < n + r; r1++) {
            sum += (r1 < 0 || r1 >= n ? 0 : tmp[r1]);

            if (r1 - l1 + 1 < 2 * r + 1) continue;

            if (sum < t) {
                cnt += t - sum;
                int idx = min(r1, n - 1);
                tmp[idx] += t - sum;
                sum += t - sum;
            }
            sum -= (l1 < 0 ? 0 : tmp[l1]);
            l1++;

            if (cnt > k) return 0;
        }

        return 1;
    };

    while (left + 1 < right) {
        mid = left + (right - left) / 2;
        (check(mid) ? left : right) = mid;
    }

    return left;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxPower(nums, 1, 2);

    return 0;
}
