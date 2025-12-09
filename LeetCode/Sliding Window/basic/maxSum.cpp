#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1};
long long maxSum(vector<int>& nums, int m, int k) {
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

            
            if (num1 >= m) ans = max(ans, num);
            num -= nums[i - k + 1];
            vis[nums[i - k + 1]]--;
            if (!vis[nums[i - k + 1]]) {
                num1--;
            }
            
        }
        
        cout << ans << '\n';
        return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxSum(nums, 1, 1);
    return 0;
}
