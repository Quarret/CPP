#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumCost(vector<int>& nums) {
    int n = nums.size();
    vector<int> suf(n, INT_MAX / 2);

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = min(suf[i + 1], nums[i + 1]);
    }

    int ans = INT_MAX;
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, nums[0] + nums[i] + suf[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}