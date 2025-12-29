#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    unordered_map<int, int> mp;
    int cnt = 0;
    
    for (int x : nums) {
        mp[x]++;
        if (mp[x] == 2) {
            cnt++;
        } 
    }
    if (cnt == 0) return 0;

    int n = nums.size();
    for (int i = 0; i < n;) {
        int j = i;
        for (; i < min(j + 3, n); i++) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 1) cnt--;
        }

        if (cnt == 0) return j / 3 + 1;
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
