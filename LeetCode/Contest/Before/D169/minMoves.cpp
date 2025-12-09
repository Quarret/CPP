#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minMoves(vector<int>& nums) {
    int maxx = *max_element(nums.begin(), nums.end());
    int ans = 0;
    for (int x : nums) {
        ans += maxx - x;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
