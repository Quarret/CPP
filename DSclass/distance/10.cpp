#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    char c;
    int cnt = 0;

    while (cin >> c) {
        if (c == '1') {
            cnt++;
        } else {
            cnt--;
        }

        if (cnt == -1) {
            cout << 0 << '\n';
            return;
        }
    }

    if (cnt > 0) {
        cout << 0 << '\n';
        return;
    }

    cout << 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
