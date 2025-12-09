#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());    

    vector<bool> ans(n, false);
    vector<int> f(k + 1, 0);
    f[0] = 1;

    int i = 0;
    for (int x = 1; x <= n; x++) {
        while (i < n && nums[i] == x) {
            for (int j = k; j >= x; j--) {
                f[j] = f[j] || f[j - x];
            }
            i++;
        }

        for (int j = 0; j <= min(n - i, k / x); j++) {
            if (f[k - j * x]) {
                ans[x - 1] = true;
            }
        }
    }

    return ans;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
