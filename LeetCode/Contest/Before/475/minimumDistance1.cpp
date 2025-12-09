#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    
    int ans = INT32_MAX, n = nums.size();
    for (int k = 0; k < n; k++) {
        int x = nums[k];
        if (mp[x].size() >= 2) {
            int m = mp[x].size();
            int i = mp[x][m - 2], j = mp[x].back();
            ans = min(ans, k - i + k - j + j - i);
        } 
        mp[x].push_back(k);
    }

    return ans == INT32_MAX ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
