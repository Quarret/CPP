#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    long long l = nums1[0] + nums2[0] - 1, r = nums1.back() + nums2.back() + 1, mid = 0;

    auto check = [&](long long x) -> bool{
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((long long)nums1[i] + (long long)nums2[j] <= x) {
                    cnt++;
                    if (cnt >= k) return 1;
                } else break;
            }
        }

        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    vector<vector<int>> ans;
    vector<int> idx(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nums1[i] + nums2[j] < r) ans.push_back({nums1[i], nums2[j]});
            else {
                idx[i] = j + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = idx[i]; j < m; j++) {
            if (nums1[i] + nums2[j] == r) {
                ans.push_back({nums1[i], nums2[j]});
                if (ans.size() == k) break;
            } else break;
        }

        if (ans.size() == k) break;
    }
    

    sort(ans.begin(), ans.end(), [&](vector<int> pair1, vector<int> pair2) {
        if (pair1[0] + pair1[1] == pair2[0] + pair2[1]) return pair1[0] < pair2[0];
        return pair1[0] + pair1[1] < pair2[0] + pair2[1];
    });

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
