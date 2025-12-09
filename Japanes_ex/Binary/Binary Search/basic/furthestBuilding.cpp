#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    long long n = heights.size();
    long long l = -1, r = n, mid = 0;

    vector<long long> pre(n, 0), diff(n, 0);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + max(heights[i] - heights[i - 1], 0);
        diff[i] = max(heights[i] - heights[i - 1], 0);
    }
    
    auto check = [&](long long k) -> bool {
        vector<int> nums(diff.begin() + 1, diff.begin() + k);
        long long ans = pre[k];
        
        sort(nums.begin(), nums.end());

        if (ladders >= nums.size()) return 1;

        int idx = nums.size() - 1;
        for (int i = 0; i < ladders; i++) {
            ans -= nums[idx];
            idx--;
        }

        return ans <= bricks;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
