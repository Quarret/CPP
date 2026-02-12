#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int centeredSubarrays(vector<int>& nums) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int s = 0;
        unordered_map<int, int> mp;
        for (int j = i; j < n; j++) {
            s += nums[j];
            mp[nums[j]] = 1;
            if (mp[s]) ans++;
        }

    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}