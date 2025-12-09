#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    map<string, int> mp;
    string tmp, ans;
    for (int i = 0; i < 2 * n - 1; i++) {
        cin >> tmp;
        mp[tmp]++;
    }

    for (auto &it : mp) {
        if (it.second % 2 == 1) {
            ans = it.first;
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    while (1) {
        cin >> n;
        if (!n) {
            return 0;
        }

        solve();
    }
}
