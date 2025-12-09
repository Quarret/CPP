#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maximumOr(vector<int>& nums, int k) {
    long long ans = 0, pre = 0;
    int cnt[35]{};

    for (int x: nums) {
        for (int i = 0; i <= 31; i++) {
            if ((x & (1 << i)) == (1 << i)) cnt[i]++;
        }
        pre |= x;
    }

    int maxx = *max_element(nums.begin(), nums.end());
    int len = __bit_width(maxx);
    for (int x: nums) {
        if (__bit_width(x) == len) {
            long long tmp = pre;
            for (int i = 0; i <= 31; i++) {
                if ((x & (1 << i)) == (1 << i) && cnt[i] == 1) tmp ^= (1 << i);
            }
            tmp |= ((1LL * x) << k);
            ans = max(ans, tmp);
        }
    }

    return ans;
}

/*
题目的原理很明晰:使或值二进制串尽可能长
我的做法又是在找最长，这是我的思维陷阱，希望通过人脑思考来一锤定音找到最适合的那个数，其实只要不断枚举每种可能即可
主要时间复杂度差异在如何处理 num << k与其他数的或值
在这里学习灵神的思路:前缀＋后缀
*/

long long maximumOr(vector<int>& nums, int k) {
    long long ans = 0, pre = 0, n = nums.size();
    vector<long long> suf(n + 1, 0);
    suf[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] | nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, pre | suf[i] | ((1LL * nums[i]) << k));
        pre |= nums[i];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
