#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int smallestBalancedIndex(vector<int>& nums) {
    using ll = long long;
    ll pre = 0, mul = 1, n = nums.size();
    for (ll x : nums) {
        pre += x;
    }

    for (int i = n - 1; i > 0; i--) {
        ll x = nums[i];
        pre -= x;
        if (pre == mul) return i;
        
        if ((pre - nums[i - 1]) / x < mul) {
            break;
        }
        mul *= x;
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}