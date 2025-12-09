/*** 
 * @Author: Quarret
 * @Date: 2025-06-08 09:17:34
 * @LastEditTime: 2025-06-08 09:29:33
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();
    sort(nums.begin(), nums.end());
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    vector<long long> ans;
    for (int i = 0; i < m; i++) {
        int idx = lower_bound(nums.begin(), nums.end(), queries[i] + 1) - nums.begin() - 1;
        ans.push_back(1LL * (idx + 1) * queries[i] - pre[idx + 1] + (pre[n] - pre[idx + 1]) - 1LL * (n - idx - 1) * queries[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
