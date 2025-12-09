#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int peopleAwareOfSecret(int n, int delay, int forget) {
    int MOD = 1e9 + 7;
    vector<int> memo(n + 1, -1);
    
    auto dfs = [&](this auto&& dfs, int i) -> int {
        if (i > n) return 0;

        int &res = memo[i];
        if (res != -1) return res;

        res = 0;
        for (int j = i + delay; j < i + forget; j++) {
            if (j + forget > n && j <= n) {
                res++;
            }
            res = (res + dfs(j)) % MOD;
        }

        return res % MOD;
    };

    int ans = dfs(1);
    if (1 + forget > n) ans++;
    return ans;
}

int peopleAwareOfSecret(int n, int delay, int forget) {
    int MOD = 1e9 + 7, ans = 0;
    // know[i] 表示恰好在第i天知道的人数
    vector<int> know(n + 1);

    know[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (i + forget > n) ans = (ans + know[i]) % MOD;

        for (int j = i + delay; j <= min(n, i + forget - 1); j++) {
            know[j] = (know[j] + know[i]) % MOD;
        }
    }

    return ans % MOD;
}

int peopleAwareOfSecret(int n, int delay, int forget) {
    int MOD = 1e9 + 7;
    vector<int> pre(n + 1);
    
    pre[1] = 1;
    for (int j = 2; j <= n; j++) {
        int know = pre[max(j - delay, 0)] - pre[max(j - forget, 0)];
        pre[j] = (pre[j - 1] + know) % MOD;
    }

    int ans = pre[max(n - delay, 0)] - pre[max(n - forget, 0)];
    return (ans % MOD + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
