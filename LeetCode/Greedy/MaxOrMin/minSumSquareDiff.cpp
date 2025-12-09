#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    long long ans = 0;
    long long n = nums1.size(), k = k1 + k2, x = -1;
    unordered_map<int, long long> cnt;

    for (int i = 0; i < n; i++) {
        long long y = 1LL * abs(nums1[i] - nums2[i]);
        cnt[y]++;
        x = max(x, y);
        ans += y * y;
    }

    while (x != 0 && k) {
        long long num = min(cnt[x], k);
        k -= num;
        cnt[x - 1] += num;
        ans -= (x * x - (x - 1) * (x - 1)) * num;
        x--;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
