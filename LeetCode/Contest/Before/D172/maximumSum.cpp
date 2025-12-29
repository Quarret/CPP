#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumSum(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    for (int x : nums) {
        mp[x % 3].push_back(x);
    }
    
    for (auto &[_, arr] : mp) {
        ranges::sort(arr, greater());
    }

    int maxx = 0;
    if (mp[0].size() >= 3) {
        maxx = max(maxx, mp[0][0] + mp[0][1] + mp[0][2]);
    }
    if (mp[0].size() >= 1 && mp[1].size() >= 1 && mp[2].size() >= 1) {
        maxx = max(maxx, mp[0][0] + mp[1][0] + mp[2][0]);
    }
    if (mp[1].size() >= 3) {
        maxx = max(maxx, mp[1][0] + mp[1][1] + mp[1][2]);
    }
    if (mp[2].size() >= 3) {
        maxx = max(maxx, mp[2][0] + mp[2][1] + mp[2][2]);
    }

    return maxx;
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
