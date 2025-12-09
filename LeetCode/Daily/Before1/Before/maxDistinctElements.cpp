#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int pre = INT32_MIN, ans = 0;
    for (int i = 0; i < n; i++) {
        int res = min(max(pre + 1, nums[i] - k), nums[i] + k);
        if (res >= pre + 1) ans++;
        pre = res;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
