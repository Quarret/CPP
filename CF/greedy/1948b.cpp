#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, num, num1, num2;
    cin >> n;
    vector<int> a(n);

    for (auto& x : a) cin >> x;
    vector<int> b({a[n - 1]});

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > b.back()) {
            b.push_back(a[i] % 10);
            b.push_back(a[i] / 10);
        } else {
            b.push_back(a[i]);
        }
    }

    cout << (is_sorted(b.rbegin(), b.rend()) ? "YES" : "NO") << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
