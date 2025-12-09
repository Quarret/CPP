#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countPartitions(vector<int>& nums) {
    int sum = reduce(nums.begin(), nums.end());
    
    int left = 0, n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        left += nums[i];
        int right = sum - left;
        if (((left - right) % 2 + 2) % 2 == 0) {
            ans++;
        }
    }

    return ans;
}

// l - (s - l) = 2l - s 为偶数, 所以 s 为偶数
int countPartitions(vector<int>& nums) {
    int s = reduce(nums.begin(), nums.end());
    return s % 2 ? 0 : nums.size() - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
