#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << '\n';
        return;
    }

    int l = 1, r = n + 1, mid = floor((l + r) / 2);
    if (a[mid] == x) {
            cout << 0 << '\n';
            return;
        }
    while (r - l != 1) {
        


    }
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
