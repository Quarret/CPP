#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxNumOfMarkedIndices(vector<int>& nums) {
    int l = -1, r = nums.size() / 2 + 1, n = nums.size(), mid = 0;
    sort(nums.begin(), nums.end());

    auto check = [&](int k) -> bool {
        int j = n - k;

        for (int i = 0; i < k; i++) {
            if (nums[j] < 2 * nums[i]) return 0;
            j++;
        }

        return 1;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return (l == -1 ? 0 : 2 * l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
