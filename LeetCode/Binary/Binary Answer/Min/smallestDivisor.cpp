#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long divsum(vector<int>& nums, int div) {
    long long sum = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        sum += (nums[i] + div - 1) /div;
    }

    return sum;
}
int check(vector<int>& nums, int threshold, int left, int right) {
    long long l = left, r = right, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (divsum(nums, mid) > threshold) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    long long minn = 1e9, maxx = -1, n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        minn = min(minn, (long long)nums[i]);
        maxx = max(maxx, (long long)nums[i]);
    }
    
    int left = minn, right = maxx;

    ans = check(nums, threshold, left, right);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
