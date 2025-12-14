#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestEqualSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> pos_lists(n + 1);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        pos_lists[x].push_back(i - pos_lists[x].size());
    }

    int ans = 0;
    for (auto &pos : pos_lists) {
        int m = pos.size();
        for (int r = 0, l = 0; r < m; r++) {
            while (pos[r] - pos[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
