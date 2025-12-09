#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> nums(n);
    
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        nums[i] = nums1[i] - nums2[i];
        s1 += nums1[i];
        s2 += nums2[i];
    }

    int f0 = 0, f1 = 0, maxx = -1e9, minn = 1e9;
    for (int i = 0; i < n; i++) {
        f0 = min(f0, 0) + nums[i];
        f1 = max(f1, 0) + nums[i];

        minn = min(minn, f0);
        maxx = max(maxx, f1);
    }

    return max(s1 - minn, s2 + maxx);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
