#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    
    int ans = INT_MAX;
    for (int k = 0; k < nums.size(); k++) {
        int x = nums[k];
        if (mp[x].size() >= 2) {
            int m = mp[x].size();
            int i = mp[x][m - 2], j = mp[x].back();
            ans = min(ans, j - i + k - i + k - j);
        }
        mp[x].push_back(k);
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}