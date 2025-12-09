#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countGood(vector<int>& nums, int k) {
    long long n = nums.size(), l = 0, ans = 0, num = 0;
     unordered_map<long, long> mp;

     for (int r = 0; r < n; r++) {
         mp[nums[r]]++;
         num += mp[nums[r]] - 1;

         while (num >= k) {
             num -= mp[nums[l]] - 1;
             mp[nums[l]]--;
             l++;
         }

         ans += l;
     }

     return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
