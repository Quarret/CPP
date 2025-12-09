#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    vector<int> windows;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        windows.push_back(nums[i]);

        if (windows.size() < 2 * k) continue;
        int ok = 1;
        for (int j = 0; j < k - 1; j++) {
            if (windows[j] >= windows[j + 1]) ok = 0;
        }

        for (int j = k; j < 2 * k - 1; j++) {
            if (windows[j] >= windows[j + 1]) ok = 0;
        }

        if (ok) return true;
        if (!ok) windows.erase(windows.begin());
    }

    return false;
}

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0, cnt = 0, pre = 0;

    for (int i = 0; i < n; i++) {
        cnt++;
        if (i == n - 1 || nums[i] >= nums[i + 1]) {
            ans = max({ans, cnt / 2, min(pre, cnt)});
            pre = cnt;
            cnt = 0;
        }

        if (ans >= k) return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
