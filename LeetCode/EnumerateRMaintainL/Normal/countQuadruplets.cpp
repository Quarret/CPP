#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countQuadruplets(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int num = nums[i] + nums[j] + nums[k];
                int idx = lower_bound(mp[num].begin(), mp[num].end(), k + 1) - mp[num].begin();
                ans += mp[num].size() - idx;
            }
        }
    }

    return ans;
}

/*
枚举b来枚举a,c,d
*/
int countQuadruplets(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    unordered_map<int, int> mp;

    for (int b = n - 3; b >= 1; b--) {//c随着b的枚举逐个枚举完
        for (int d = b + 2; d < n; d++) {
            mp[nums[d] - nums[b + 1]]++;
        }

        for (int a = 0; a < b; a++) {
            ans += mp[nums[a] + nums[b]];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
