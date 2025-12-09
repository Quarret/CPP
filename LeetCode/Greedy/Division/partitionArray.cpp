#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int partitionArray(vector<int>& nums, int k) {
    int maxx = INT_MIN, minn = INT_MAX;
    int ans = 1;
    ranges::sort(nums);
    
    for (int x : nums) {
        maxx = max(maxx, x);
        minn = min(minn, x);
        if (maxx - minn > k) {
            ans++;
            maxx = x;
            minn = x;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
