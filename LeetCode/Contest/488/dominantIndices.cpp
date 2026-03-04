#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dominantIndices(vector<int>& nums) {
    int sum = reduce(nums.begin(), nums.end()), n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum -= nums[i];
        if (nums[i] * (n - i - 1) > sum) ans++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}