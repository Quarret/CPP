#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countElements(vector<int>& nums, int k) {
    int n = nums.size();
    ranges::sort(nums);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(nums.begin(), nums.end(), nums[i] + 1) - nums.begin();
        if (n - pos >= k) {
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
