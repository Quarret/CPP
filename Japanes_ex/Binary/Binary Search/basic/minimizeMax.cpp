#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimizeMax(vector<int>& nums, int p) {
    if (!p) return 0;
    
    int n = nums.size();
    int l = -1, r = 0, mid = 0;
    sort(nums.begin(), nums.end());

    r = nums.back() + 1;

    auto check = [&](int k) -> bool {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= k) {
                cnt++;
                i++;
            }

            if (cnt >= p) return 1;
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
