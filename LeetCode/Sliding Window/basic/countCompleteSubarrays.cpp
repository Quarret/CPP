#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size(), k = 0, l = 0, ans = 0, num = 0;
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) mp[nums[i]]++;

    k = mp.size();
    mp.clear();

    for (int r = 0; r < n; r++) {
        if (!mp[nums[r]]) num++;
        mp[nums[r]]++;

        while (num == k) {
            if (mp[nums[l]] == 1) num--;
            mp[nums[l]]--;
            l++;
        }

        ans += l;
    }

    return ans;
}    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
