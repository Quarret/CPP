/*** 
 * @Author: Quarret
 * @Date: 2025-06-09 12:22:52
 * @LastEditTime: 2025-06-09 12:26:13
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;
    while (!a[l]) l++;
    while (!a[r]) r--;

    cout << (x >= r - l + 1 ? "Yes\n" : "No\n");
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
