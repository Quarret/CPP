#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    int num = 3;
    while (--num)

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - k; i < n; i++) {
        cout << a[i] << ' ';
    }

    for (int i = 0; i < n - k; i++) {
        cout << a[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
