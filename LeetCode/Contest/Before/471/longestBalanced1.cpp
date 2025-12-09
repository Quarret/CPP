#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 分类讨论
int longestBalanced(string s) {
    int ans = 0, n = s.size();
    vector pre(3, vector<int>(n + 1, 0));

    // 一种字母
    for (int r = 0, l = 0; r < n; r++) {
        if (s[r] != s[l]) l = r;
        pre[0][r + 1] = pre[0][r] + (s[r] == 'a');
        pre[1][r + 1] = pre[1][r] + (s[r] == 'b');
        pre[2][r + 1] = pre[2][r] + (s[r] == 'c');
        ans = max(ans, r - l + 1);
    }

    // 两种字母
    auto f = [&](char x, char y) -> void {
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp = {{0, i - 1}};
            
            int d = 0;
            for (; i < n && (s[i] == x || s[i] == y); i++) {
                d += s[i] == x ? 1 : -1;
                if (mp.contains(d)) {
                    ans = max(ans, i - mp[d]);
                } else {
                    mp[d] = i;
                }
            }
        }
    };

    f('a', 'b');
    f('a', 'c');
    f('b', 'c');

    // 三种字母
    unordered_map<long long, int> mp = {{1LL * n << 32 | n, -1}};
    for (int i = 0; i < n; i++) {
        long long val = (1LL * (pre[0][i + 1] - pre[1][i + 1] + n) << 32) | (pre[1][i + 1] - pre[2][i + 1] + n);
        if (mp.contains(val)) {
            ans = max(ans, i - mp[val]);
        } else {
            mp[val] = i;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
