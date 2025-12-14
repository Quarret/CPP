#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfWays(string corridor) {
    long long ans = 1, n = corridor.size(), MOD = 1e9 + 7;
    vector<int> pre(n + 1), suf(n + 1);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (corridor[i] == 'S');
    }
    if (pre[n] % 2 || !pre[n]) return 0;

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (corridor[i + 1] == 'S');
    }

    for (int i = 0; i < n - 1; i++) {
        if (pre[i + 1] % 2 == 0 && suf[i] % 2 == 0) {
            long long j = i;
            for (; j < n - 1; j++) {
                if (pre[j + 1] % 2 == 0 && suf[j + 1] % 2 == 0 && pre[j + 1] != 0 && suf[j + 1] != 0) {
                    continue;
                } else break;
            }
            ans = (ans * (j - i + 1) % MOD) % MOD;
            i = j;
        }
    }

    return ans;
}

// 一次遍历
int numberOfWays(string corridor) {
    long long ans = 1, n = corridor.size();
    int cnt_s = 0, last_s = 0, MOD = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        if (corridor[i] == 'S') {
            cnt_s++;

            
            // 奇数个时, i = last_s + 1, 不影响结果
            if (cnt_s >= 3 && cnt_s % 2) {
                ans = (ans * (i - last_s) % MOD) % MOD;
            }
            last_s = i;
        }
    }

    if (cnt_s % 2 || !cnt_s) return 0;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
