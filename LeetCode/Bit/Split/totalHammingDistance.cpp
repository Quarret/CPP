#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int ans = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += __builtin_popcount(nums[i] ^ nums[j]);
        }
    }

    return ans;
}

/*
拆位法：根据位上数字不同分类
*/
int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    
    for (int i = 0; i <= 31; i++) {
        int cnt0 = 0, cnt1 = 0;

        for (int x : nums) {
            if ((x & (1 << i)) == (1 << i)) cnt1++;
            else cnt0++;
        }

        ans += cnt0 * cnt1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
