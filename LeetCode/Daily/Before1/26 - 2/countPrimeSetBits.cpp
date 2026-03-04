#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countPrimeSetBits(int left, int right) {
    unordered_map<int, int> mp;
    mp[2] = 1;
    mp[3] = 1;
    mp[5] = 1;
    mp[7] = 1;
    mp[11] = 1;
    mp[13] = 1;
    mp[17] = 1;
    mp[19] = 1;
    mp[23] = 1;

    int ans = 0;
    for (int x = left; x <= right; x++) {
        // __builtin_ 代表编译器直接映射硬件指令
        if (mp[__builtin_popcount(x)]) ans++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}