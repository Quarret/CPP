#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int numSub(string s) {
    int n = s.size(), MOD = 1e9 + 7;
    int cnt0 = 0, cnt1 = 0, ans = 0;
    for (int r = 0, l = 0; r < n; r++) {
        (s[r] == '1' ? cnt1 : cnt0) += 1;

        if (s[r] == '0') continue;

        while (cnt0) {
            cnt0 -= s[l++] == '0';
        }
        ans = (ans + r - l + 1) % MOD;
    }
    
    return ans;
}

// 记录最新的 0 位置
int numSub(string s) {
    int MOD = 1e9 + 7;
    int ans = 0, n = s.size();
    int last0 = -1;
    
    for (int r = 0; r < n; r++) {
        if (s[r] == '0') {
            last0 = r;
        } else {
            ans += r - last0; // 右端点为 r 的全 1 串
            ans %= MOD;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
