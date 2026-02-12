#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
1 2 4
x = 1 pre = 1
x = 2 pre = 2 + 1
x = 4 pre = 4 + 2 + 2 * 1
*/

int sumOfPower(vector<int>& nums) {
    const int MOD = 1e9 + 7;
    ranges::sort(nums);

    long long pre = 0, ans = 0, prev = 0;
    for (int x : nums) {
        pre = (pre + (((pre - prev) % MOD) + MOD) % MOD + x) % MOD;
        long long mx = (1LL* x % MOD * 1LL* x % MOD) % MOD;
        ans = (ans + (mx * pre % MOD) % MOD) % MOD;
        prev = x;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}