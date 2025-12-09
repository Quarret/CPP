/*** 
 * @Author: Quarret
 * @Date: 2025-06-09 09:12:33
 * @LastEditTime: 2025-06-09 09:18:12
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
4 3 1 2 4
100 011 001 010 100

特殊数组满足：子数组每个数位上的1的个数都为偶数，即prediffxor = 0
所以prexor[j] - prexor[i] == 0
迭代不变量prexor[j]
*/
long long beautifulSubarrays(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, long long> mp;
    long long prexor = 0, ans = 0;
    mp[0]++;

    for (auto& num: nums) {
        prexor ^= num;
        ans += mp[prexor]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
