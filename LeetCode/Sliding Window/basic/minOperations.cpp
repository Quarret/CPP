#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int n = nums.size(), l = 0, ans = 1e9, num = 0;
    
    for (int r = 0; r < 2 * n - 1; r++) {
        num += nums[r % n];

        while (num > x) {
            num -= nums[l % n];
            l++;
        }

        if (num == x) ans = min(ans, r - l + 1);
    }

    return (ans == 1e9 ? - 1 : ans);
}

/*
逆向思维，找最长的子数列和为 \sum nums[i] - x
*/
vector<int> nums = {1, 1};
int minOperations(vector<int>& nums, int x) {
    int n = nums.size(), l = 0, ans = -1, num = 0, k = 0;
    
    for (int i = 0; i < n; i++) k += nums[i];
    k -= x;
    if (k < 0) return -1;

    for (int r = 0; r < n; r++) {
        num += nums[r];

        while (num > k) {
            num -= nums[l];
            l++;
        }

        if (num == k) ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
    return (ans == -1 ? -1 : n - ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    minOperations(nums, 2);
    return 0;
}
