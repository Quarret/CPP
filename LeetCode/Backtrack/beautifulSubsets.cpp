#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int beautifulSubsets(vector<int>& nums, int k) {
    int n = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int t = 1; t < (1 << n); t++) {
        int ok = 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if ((t >> i & 1) == 0) continue;
            if (mp[nums[i] - k]) {
                ok = 0;
            }
            mp[nums[i]] = 1;
        }

        ans += ok;
    }
    
    return ans;
}

int beautifulSubsets(vector<int>& nums, int k) {
    int n = nums.size(), ans = -1; // ans 初始化为 -1 去掉空集
    unordered_map<int, int> mp; // 尽量全局 map

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans++;
            return;
        }

        dfs(i + 1);
        if (!mp[nums[i] - k] && !mp[nums[i] + k]) {
            mp[nums[i]]++;
            dfs(i + 1);
            mp[nums[i]]--;
        }
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
