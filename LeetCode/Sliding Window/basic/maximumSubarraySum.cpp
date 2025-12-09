#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1};
long long maximumSubarraySum(vector<int>& nums, int k) {
        int n  = nums.size();
        unordered_map<int, int> vis;
        long long num = 0, ans = 0, num1 = 0;
        
        for (int i = 0; i < n; i++) {
            num += nums[i];

            if (vis[nums[i]] == 0) {
                num1++;
            }
            vis[nums[i]]++;

            if (i < k - 1) continue;

            
            if (num1 == k) ans = max(ans, num);
            num -= nums[i - k + 1];
            vis[nums[i - k + 1]]--;
            if (!vis[nums[i - k + 1]]) {
                num1--;
            }
            
        }
        
        return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
