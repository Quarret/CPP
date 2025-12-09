#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, maxn = -1, minn = 1e9, minN = 1e9, x = 0;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (minN > abs(abs(a[i] - maxn) -(a[i]- minn))) {
           minN = abs(abs(a[i] - maxn) -(a[i]- minn));
           x = a[i];
        } 
    }

    cout << x << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
