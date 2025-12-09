#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> weights = {5, 5, 5};
int shipWithinDays(vector<int>& weights, int days) {
    int l = -1, r = 0, n = weights.size(), mid = 0;
    for (int i = 0; i < n; i++) {
        l = max(l, weights[i]);
        r += weights[i];
    }
    
    auto check = [&](int k) -> int{
        int ans = 0, tmp = 0;

        for (int i = 0; i < n; i++) {
            if (tmp + weights[i] > k) {
                ans++;
                tmp = 0;
            } else if (tmp + weights[i] == k) {
                ans++;
                tmp = 0;
                continue;
            }
            tmp += weights[i];
        }

        if (tmp > 0) ans++;

        return ans;
    };


    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid) > days) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << shipWithinDays(weights, 1);
    // vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int l = 0, r = nums.size() - 1, mid = 0;

    // while (l <= r) {
    //     mid = l + (r - l) / 2;
    //     if (nums[mid] > 11) l = mid + 1;
    //     else r = mid - 1;
    // }

    // cout << l;

    return 0;
}
