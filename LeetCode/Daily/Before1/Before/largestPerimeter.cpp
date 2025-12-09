#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    int ans = 0;
    for (int k = 2; k < n; k++) {
        int i = k - 1;
        int j = k - 2;

        if (nums[i] + nums[j] > nums[k]) {
            ans = max(ans, nums[i] + nums[j] + nums[k]);
        }
    }

    return ans;
}

int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int k = n - 1; k >= 2; k--) {
        int i = k - 2;
        int j = k - 1;

        if (nums[i] + nums[j] > nums[k]) {
            return nums[i] + nums[j] + nums[k];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
