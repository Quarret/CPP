#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minMoves2(vector<int>& nums) {
    ranges::sort(nums);
    int n = nums.size();

    int median =  nums[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(nums[i] - median);
    }
    return ans;    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
