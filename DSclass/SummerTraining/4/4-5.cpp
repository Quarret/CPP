#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n, ans = 0;
    cin >> n;
    vector<int> a ={100, 20, 10 ,5 ,1};

    for (int i = 0; i < 5; i++) {
        ans += n / a[i];
        n %= a[i];
        if (!n) break;
    }

    cout << ans << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
