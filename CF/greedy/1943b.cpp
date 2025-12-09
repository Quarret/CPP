#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, num, maxx = -1e9;
    cin >> n;
    int a[n + 1] = {0};

    for (int i = 0; i < n; i++) {
        cin >> num;
        a[num]++;
        maxx = max(maxx, num);
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            cout << i + 1 << '\n';
            return;
        } else if (a[i] == 0) {
            cout << i << '\n';
            return;
        }
    }

    cout << maxx + 1 << '\n';
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
