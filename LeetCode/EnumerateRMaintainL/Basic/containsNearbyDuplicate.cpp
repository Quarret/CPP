#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (mp[nums[i]] && i + 1 - mp[nums[i]] <= k) return true;
        mp[nums[i]] = i + 1;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
