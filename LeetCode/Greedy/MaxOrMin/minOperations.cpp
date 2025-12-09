#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    // int s1 = accumulate(nums1.begin(), nums1.end(), 0);        
    // int s2 = accumulate(nums2.begin(), nums2.end(), 0);
    int s1 = reduce(nums1.begin(), nums1.end());        
    int s2 = reduce(nums2.begin(), nums2.end());
    
    if (n > 6 * m || 6 * n < m) return -1;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int diff = s1 - s2;
    if (diff < 0) {
        diff = -diff;
        swap(nums1, nums2);
    }
    
    int i = 0, j = nums1.size() - 1;
    int ans = 0;
    while (diff > 0) {
        int change1 = j >= 0 ? nums1[j] - 1 : -1;
        int change2 = i < nums2.size() ? 6 - nums2[i] : - 1;
        if (change1 > change2) {
            diff -= min(diff, change1);
            ans++;
            j--;
        } else {
            diff -= min(diff, change2);
            ans++;
            i++;
        }
    }

    return ans;
}

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if (6 * n < m || n > 6 * m) {
        return -1;
    }

    int s = accumulate(nums1.begin(), nums1.end(), 0) - accumulate(nums2.begin(), nums2.end(), 0);
    if (s < 0) {
        swap(nums1, nums2);
    }

    int cnt[6]{};
    for (int x : nums1) {
        cnt[x - 1]++;
    }

    for (int x : nums2) {
        cnt[6 - x]++;
    }

    int ans = 0;
    for (int x = 5; ; x--) {
        if (s <= x * cnt[x]) {
            return ans + (s + x - 1) / x;
        }
        ans += cnt[x];
        s -= x * cnt[x];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
