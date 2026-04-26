#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minMirrorPairDistance(vector<int>& nums) {
    unordered_map<int, int> mp;

    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end()) {
            ans = min(ans, i - mp[nums[i]]);
        }
        string s = to_string(nums[i]);
        ranges::reverse(s);
        int t = stoi(s);
        mp[t] = i;
    }
    
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}