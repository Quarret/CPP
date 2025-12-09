#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minMirrorPairDistance(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        string s = to_string(a[i]);
        ranges::reverse(s);
        a[i] = stoi(s);
    }
    
    int ans = INT_MAX;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.contains(nums[i])) {
            ans = min(ans, i - mp[nums[i]]);
        }
        mp[a[i]] = i;
    }

    return ans == INT_MAX ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
