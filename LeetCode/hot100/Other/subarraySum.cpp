#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    
    int pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        pre += nums[i];
        ans += cnt[k - pre];
        cnt[pre]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
