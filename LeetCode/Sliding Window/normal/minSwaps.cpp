#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minSwaps(vector<int>& nums) {
        int n = 0, m = nums.size();
        for (int i = 0; i < m; i++) if (nums[i]) n++;

        int num = 0, ans = 1e9;
        for (int i = 0; i < n + m; i++) {
            num += nums[i % m];

            if (i < n - 1) continue;

            ans = min(ans, n - num);
            num -= nums[(i - n + 1) % m];
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
