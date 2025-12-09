#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findSmallestInteger(vector<int>& nums, int value) {
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[(x % value + value) % value]++;
    }
    
    int ans = 0;
    while (1) {
        if (!mp[ans % value]) break;
        mp[ans % value]--;
        ans++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
