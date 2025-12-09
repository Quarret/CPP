#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<int, int> mp;
void solve() {
    int n, maxx = 0, num, id, ans;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> id >> num;
        mp[id] += num;
        if (mp[id] > maxx) {
            ans = id;
            maxx = mp[id];
        }
    }

    cout << ans << ' ' << maxx << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
