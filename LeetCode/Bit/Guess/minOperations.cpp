#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int maxx = *max_element(nums.begin(), nums.end());
    int ans = max(__bit_width(maxx) - 1, 0);
    
    for (int x : nums) {
        ans += __builtin_popcount(x);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
