#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int ans = 0;

    for (int i = 29; i >= 0; i--) {
        int target = (ans >> i) | 1;
        
        int ok = 0;
        unordered_map<int, int> mp;
        for (int x : nums) {
            int y = x >> i;
            if (mp[target ^ y]) {
                ok = 1;
                break;
            }
            mp[y] = 1;
        }

        if (ok) ans |= 1 << i;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}