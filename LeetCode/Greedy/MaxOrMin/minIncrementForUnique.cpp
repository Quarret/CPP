#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minIncrementForUnique(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    unordered_map<int, int> mp;
    vector<int> a;

    for (int x : nums) {
        if (!mp[x]) {
            mp[x] = 1;
        } else {
            a.push_back(x);
        }
    }

    unsigned ans = 0;
    int minn = INT32_MIN;
    for (int x : a) {
        minn = max(minn, x);
        while (mp[minn]) {
            minn++;
            ans++;
        }
    }
    
    return ans;
}

// 紧紧挨着一起
int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0, n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] <= nums[i - 1]) {
            ans += nums[i - 1] + - nums[i];
            nums[i] = nums[i - 1] + 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
