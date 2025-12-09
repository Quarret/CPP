#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int subarraySum(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    int ans = 0, start = 0;

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + nums[i];
        start = max(0, i - nums[i]);

        ans += pre[i + 1] - pre[start];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
