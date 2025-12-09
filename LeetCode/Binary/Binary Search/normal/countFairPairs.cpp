#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int check(vector<int>& nums, int start, int k) {
    int l = start, r = nums.size() - 1, mid = 0;
   
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long n = nums.size(), num1 = 0, num2 = 0, ans = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        num1 = check(nums, i + 1, lower - nums[i]); 
        num2 = check(nums, i + 1, upper - nums[i] + 1);
        ans += num2 - num1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
