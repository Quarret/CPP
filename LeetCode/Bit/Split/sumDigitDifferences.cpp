#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long sumDigitDifferences(vector<int>& nums) {
    long long ans = 0;
    unordered_map<int, long long> cnt;
    
    while (nums[0]) {
        for (int &x : nums) {
            cnt[x % 10]++;
            x /= 10;
        }

        long long sum = 0;
        for (int i = 0; i < 10; i++) sum += cnt[i];
        for (int i = 0; i < 10; i++) {
            sum -= cnt[i];
            ans += cnt[i] * sum;
        }
        cnt.clear();
    }

    return ans;
}

/*
反向思维：前去相同数位数对 + 枚举右维护左
*/

long long sumDigitDifferences(vector<int>& nums) {
    long long n = nums.size(), m = to_string(nums[0]).size();
    long long ans = m * n * (n - 1) / 2;
    vector<array<int, 10>> cnt(m);

    for (int x : nums) {
        for (int i = 0; x; x /= 10) {
            ans -= cnt[i++][x % 10]++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);    
    cin.tie(NULL);

    

    return 0;
}
