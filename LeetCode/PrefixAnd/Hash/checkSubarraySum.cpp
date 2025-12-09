#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int j = 1; j <= n; j++) {
        if (pre[j] % k == 0 && j >= 2) return true;
        else if (mp[pre[j] % k] && j - mp[pre[j] % k]>= 2) return true;
        if (mp[pre[j] % k] == 0) mp[pre[j] % k] = j;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
