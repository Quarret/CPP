#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int func(int x) {
    int num = 0;
    while (x) {
        num += x % 10;
        x /= 10;
    }

    return num;
}
int maximumSum(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        int num = func(nums[i]);

        if (mp[num]) {
            ans = max(ans, nums[i] + mp[num]);
        }

        mp[num] = max(nums[i], mp[num]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
