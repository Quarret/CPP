#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int maximumCount(vector<int>& nums) {
        int n = nums.size(), pos = n - check(nums, 1), neg = check(nums, 0);
        return max(pos, neg);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
