#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, c, d, tmp;
    cin >> n >> c >> d;

    vector<int> a;
    for (int i = 0; i < n * n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    int num = a[0];

    vector<int> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b.push_back(num + i * c + j * d);
        }
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < n * n; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES" << '\n';
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
