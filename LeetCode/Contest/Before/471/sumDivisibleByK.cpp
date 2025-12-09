#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int sumDivisibleByK(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    
    int ans = 0;
    for (auto [x, c] : mp) {
        if (c % k == 0) ans += x * c;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
