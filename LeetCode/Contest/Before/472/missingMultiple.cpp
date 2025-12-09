#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int missingMultiple(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[x] = 1;
    }
    
    int ans = k;
    while (1) {
        if (!mp[ans]) break;
        ans += k; 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
