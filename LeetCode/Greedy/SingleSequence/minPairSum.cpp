#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minPairSum(vector<int>& nums) {
    int n = nums.size(), ans = -1;
    sort(nums.begin(), nums.end());
    int i = 0, j = n - 1;
    
    while (i < j) {
        ans = max(ans, nums[i++] + nums[j--]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
