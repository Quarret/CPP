#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isDigitorialPermutation(int n) {
    using ll = long long;
    vector<ll> a;
    ll s = 0;
    for (int x = n; x > 0; x /= 10) {
        ll res = x % 10, frac = res;
        a.push_back(res);

        frac = max(frac, 1LL);
        for (int i = 1; i < res; i++) {
            frac *= i;
        }
        s += frac;
    }
    ranges::sort(a);

    int m = a.size();
    do {
        int ok = 1;
        for (int i = 0; i < m; i++) {
            if (!a[i]) {
                ok = 0;
                break;
            } else break;
        }
        if (!ok) continue;

        int num = 0;
        for (int i = 0; i < m; i++) {
            num = num * 10 + a[i];
        }
        if (num == s) return true;
    } while (next_permutation(a.begin(), a.end()));

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}