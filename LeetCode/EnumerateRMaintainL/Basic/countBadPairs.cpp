/*** 
 * @Author: Quarret
 * @Date: 2025-05-07 08:45:14
 * @LastEditTime: 2025-06-04 12:18:13
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countBadPairs(vector<int>& nums) {
    long long n = nums.size();
    unordered_map<long long, long long> mp;
    long long ans = n * (n - 1) / 2;

    for (int i = 0; i < n; i++) {
        ans -= mp[i - nums[i]];//迭代不变量

        mp[i - nums[i]]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
