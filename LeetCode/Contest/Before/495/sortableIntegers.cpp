#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int sortableIntegers(vector<int>& nums) {
    int n = nums.size();
    vector<int> d;
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (n / i != i) d.push_back(n / i);
        }
    }

    int ans = 0;
    for (int k : d) {
        int ok = 1;
        int pre = -1;
        for (int i = 0; i < n; i += k) {
            int uptodown = 0, mx = -1, mn = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (nums[i + j] > nums[i + ((j + 1) % k)]) {
                    uptodown++;
                }
                mn = min(mn, nums[i + j]);
                mx = max(mx, nums[i + j]);
                if (uptodown > 1) ok = 0;
            }
            if (pre > mn) {
                ok = 0;
                break;
            }
            pre = mx;
        }

        if (ok) ans += k;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}