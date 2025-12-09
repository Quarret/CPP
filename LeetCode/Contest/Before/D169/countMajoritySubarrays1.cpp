#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long countMajoritySubarrays(vector<int>& nums, int target) {
    vector<long long> arr;
    arr.push_back(1);
    int cnt = 0, n = nums.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cnt += nums[i] == target;
        long long x = 2LL * cnt - i;
        if (x - 1 < arr[0]) {
            arr.insert(arr.begin(), x);
            continue;
        } else if (x - 1 > arr.back()) {
            arr.push_back(x);
            continue;
        }

        long long idx = upper_bound(arr.begin(), arr.end(), x - 1) - arr.begin();
        ans += idx;
        arr.insert(arr.begin() + idx, x);
    }

    return ans;
}

long long countMajoritySubarrays(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    // s 为前一前缀和, f 为小于前一个 s 的子数组个数
    long long ans = 0, f = 0, s = 0;
    for (int x : nums) {
        if (x == target) {
            f += mp[s];
            s++;
        } else {
            s--;
            f -= mp[s];
        }
        ans += f;
        mp[s]++;
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
