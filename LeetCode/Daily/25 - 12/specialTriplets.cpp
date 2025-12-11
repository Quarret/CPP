#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int specialTriplets(vector<int>& nums) {
    unordered_map<int, long long> pre, suf;
    
    long long ans = 0;
    const int MOD = 1e9 + 7;
    for (int x : nums) {
        suf[x]++;
    }

    for (int x : nums) {
        suf[x]--;
        if (pre.contains(2 * x) && suf.contains(2 * x)) {
            ans = (ans + 1LL * pre[2 * x] % MOD * suf[2 * x]% MOD) % MOD;
        }
        pre[x]++;   
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
