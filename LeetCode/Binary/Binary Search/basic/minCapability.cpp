#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minCapability(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = *max_element(nums.begin(), nums.end()) + 1, mid = 0;

    auto check = [&](int t) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t >= nums[i]) {
                cnt++;
                i++;
            }

            if (cnt == k) return 1;
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
