#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
未sort，只能用O(n ^ 2)来check
注意这题其实与idx号位置无关，可以sort排序
*/
int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    int l = -1, r = *max_element(nums.begin(), nums.end()) + 1, mid = 0;
    sort(nums.begin(), nums.end());

    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            //比nums[i] + x + 1数的个数，对数减去i
            int idx = lower_bound(nums.begin(), nums.end(), nums[i] + x + 1) - nums.begin() - 1;
            cnt += idx - i;

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
