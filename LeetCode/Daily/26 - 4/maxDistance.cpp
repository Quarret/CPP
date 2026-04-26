#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0, m = nums2.size();
    vector<int> a = nums2;
    ranges::reverse(a);
    
    for (int i = 0; i < nums1.size(); i++) {
        int idx = ranges::lower_bound(a, nums1[i]) - a.begin();
        ans = max(ans, m - 1 - idx - i);
        // cout << i << ' ' << idx << '\n';
    }
    
    return ans;
}

// 双指针
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0, i = 0;
    for (int j = 0; j < nums2.size(); j++) {
        while (i < nums1.size() && nums1[i] > nums2[j]) {
            i++;
        }

        if (i == nums1.size()) {
            break;
        }

        ans = max(ans, j - i);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}