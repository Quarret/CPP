#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
这题主要是各二进位上的奇偶校验
nums的prexor要与k各数位上的1的奇偶性相同
说到奇偶性，xor就要出现
1 ^ 1 = 0, 0 ^ 0 = 0
即奇偶性相同时，数位xor值为0，只需数出xor后1的个数即可 
*/
int minOperations(vector<int>& nums, int k) {
    vector<int> cnt(21, 0);
    int maxx = 0;
    
    for (int x: nums) {
        int idx = 0;
        while (x) {
            if (x % 2 == 1) maxx = max(maxx, idx);
            cnt[idx++] += x % 2;
            x /= 2;
        }
    }
    maxx = max(maxx, k != 0? __bit_width(k) : 1);

    int ans = 0;
    for (int i = 0; i <= maxx; i++) {
        if (cnt[i] % 2 != k % 2) ans++;
        k /= 2;
    }

    return ans;
}

int minOperations(vector<int>& nums, int k) {
    int prexor = 0;
    for (int x: nums) {
        prexor ^= x;
    }
    prexor ^= k;
    
    return __builtin_popcount(prexor);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
