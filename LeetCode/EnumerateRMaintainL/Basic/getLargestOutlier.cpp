#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int getLargestOutlier(vector<int>& nums) {
    int n = nums.size();
    int sum = 0, ans = 0;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        mp[nums[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        int num = sum - 2 * nums[i];
        if (mp[num] && mp[num] != i) ans = max(ans, num);
    }

    return ans;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
