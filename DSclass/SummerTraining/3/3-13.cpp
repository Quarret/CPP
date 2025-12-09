#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, ans = 0, num;
    cin >> n;

    vector<int> a(n), b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > b.back()) {
            num = b.size();
            ans = max(ans, num);
            while (b.back() < a[i] && !b.empty()) {
                b.pop_back();
            }
        }

        b.push_back(a[i]);
    }

    num = b.size();
    ans = max(ans, num);

    cout << ans << '\n';    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
