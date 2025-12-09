#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), ans = INT_MAX;
    sort(nums2.begin(), nums2.begin());

    do {
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += nums1[i] ^ nums2[i];
        }

        ans = min(ans, tot);
    } while (next_permutation(nums2.begin(), nums2.end()));

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
