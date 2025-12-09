#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
gcd(p[i], s[i]) != 全局gcd(?)

本题赛时未做出来
p[i] = gcd(a[i], p[i - 1])
s[i] = gcd(a[i], s[i + 1])

p[i] % a[i] == 0
s[i] % a[i] == 0
=> lcm(p[i], s[i]) % a[i] == 0

如果lcm(p[i], s[i]) 是 a[i]的k倍，则在gcd的过程中此k会自动除去

现在从p的头，s的位一路gcd来比对数字即可判断是否合理
*/

/*
利用gcd的单调性(未过)
*/
void solve() {
    int n, flag = 0;
    cin >> n;

    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++) {
        if (i >= 1 && p[i] % p[i - 1] != 0) flag = 1;
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && s[i + 1] & s[i] != 0) flag = 1;
        cin >> s[i];
    }

    if (flag) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int num = gcd(p[i], s[i + 1]);

        if (num != p.back() || num != s[0]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

/*
利用lcm(p[i], s[i]) % a[i] == 0

充要条件
存在前缀gcd p[1-n] 后缀gcds[1-n],如果存在 a[1-n] 满足前后缀条件，则a_i = lcm(p_i, s_i)
*/
void solve() {
    int n;
    cin >> n;

    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = lcm(1LL * p[i], 1LL * s[i]);
    }

    long long x = a[0];
    for (int i = 0; i < n; i++) {
        x = gcd(a[i], x);
        if (x != p[i]) {
            cout << "NO\n";
            return;
        }
    }

    x = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        x = gcd(a[i], x);
        if (x != s[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
