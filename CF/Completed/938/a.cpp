#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (2 * a <= b) {
        cout << n * a << '\n';
        return;
    }

    int num = n / 2, num1 = n % 2;
    cout << b * num + num1 * a << '\n';
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
