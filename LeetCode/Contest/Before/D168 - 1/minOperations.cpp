#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2[n];
    long long ans = 0, minn = 1e9;
    for (int i = 0; i < n; i++) {
        ans += abs(1LL * (nums1[i] - nums2[i]));
        int a = min(nums1[i], nums2[i]), b = max(nums1[i], nums2[i]);
        if (a <= m && b >= m) minn = 0;
        minn = min({minn, abs(1LL * (nums1[i] - m)), abs(1LL * (nums2[i] - m))});
    }
    
    return ans + minn + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
