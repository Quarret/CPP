#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int r;
    cin >> r;
    int num = sqrt((r + 1) * (r + 1) - r * r);

    cout << 2 * num - 1 << '\n';
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
