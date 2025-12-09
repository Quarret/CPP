#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) {
    int n = nums.size();
    int l = 0, r = *min_element(nums.begin(), nums.end()) + 1, mid = 0;

    auto check = [&](int k) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (nums[i] + k - 1) / k - 1;
            if (cnt > maxOperations) return 0;
        }

        return 1;
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
