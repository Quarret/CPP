#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 中位数: 数组中大于 k 的数字个数 - 数组中小于 k 的数字个数 >= 0
int countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> cnt = {{0, 1}};
    bool find_k = 0;

    int ans = 0, sum = 0;
    for (int x : nums) {
        if (x == k) {
            find_k = 1;
        } else if (x > k) {
            sum++;
        } else {
            sum--;
        }

        // k 左侧
        if (!find_k) {
            cnt[sum]++;
        } else {// k 右侧
            ans += cnt[sum] + cnt[sum - 1];
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
