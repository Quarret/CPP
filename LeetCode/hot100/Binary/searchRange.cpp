#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int idx1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int idx2 = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;

    if (idx1 == n || nums[idx1] != target) return {-1, -1};
    return {idx1, idx2};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
