#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long numGoodSubarrays(vector<int>& nums, int k) {
    long long ans = 0, pre = 0;
    int n = nums.size();

    unordered_map<long long, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        pre = (pre + nums[i]) % k;
        ans += 1LL * mp[pre];
        mp[pre]++;
    }
    
    // 去重: 数组只由一种元素组成, (len * num) % k == 0
    // 会重复 (cnt - len) 次, 例如 [1, 1, 1, 1] 会重复算多少次 [1]
    for (int i = 0, j = 0; i < n; i++) {
        if (i == n - 1 || nums[i] != nums[i + 1]) {
            int len = j - i + 1;
            for (int t = 1; t <= len; t++) {
                if ((1LL * t * nums[i]) % k == 0) {
                    ans -= 1LL * (len - t);
                }
            }
            j = i + 1;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
