#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[105], b[105];
void solve() {
    int n, m, x, y;
    cin >> n;
    while(n--) {
        cin >> x >> y;
        a[y] = x;
    }

    cin >> m;
    while(m--) {
        cin >> x >> y;
        b[y] = x;
    }

    for (int i = 100; i >= 0; i--) {
        if (a[i] + b[i]) {
            cout << a[i] + b[i] << ' ' << i << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
