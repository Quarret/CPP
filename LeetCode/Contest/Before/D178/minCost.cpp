#include <bits/stdc++.h>
using ll = long long;
using namespace std;



int minCost(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> cnt, cnt1;
    for (int x : nums1) {
        cnt[x]++;
        cnt1[x]++;
    }
    for (int y : nums2) cnt[y]++;
    for (auto &[x, c] : cnt) {
        if (c % 2) return -1;
    }
    
    int ans = 0;
    unordered_set<int> st(nums1.begin(), nums1.end());
    for (auto &[x, c] : cnt) {
        ans += max(c / 2 - cnt1[x], 0);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}