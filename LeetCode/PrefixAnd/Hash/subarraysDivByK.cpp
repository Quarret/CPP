/*** 
 * @Author: Quarret
 * @Date: 2025-06-01 10:51:43
 * @LastEditTime: 2025-06-09 10:42:37
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    unordered_map<int, int> mp;
    mp[0] = 1;

    int ans = 0, res = 0;
    for (int j = 1; j <= n; j++) {
        if (pre[j] % k < 0) res = pre[j] % k + k;// -1 % 5 = 4
        else res = pre[j] % k;

        ans += mp[res];
        mp[res]++;

        // for (int i = 0; i < j; i++) {
        //     if (!((pre[j] - pre[i]) % k)) ans++;
        // }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << (-5 % 5) << '\n';

    return 0;
}
