#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ans = 0, n, m, x, y;
void move(int x1, int y1) {
    if (x1 == n && y1 == m) {
        ans++;
        return;
    }

    if (x1 > n || y1 > m) {
        return;
    }

    if (abs(x1 - x) + abs(y1 - y) == 3) {
        return;
    }

    move(x1 + 1, y1);
    move(x1, y1 + 1);
}

void solve() {
    
    cin >> n >> m >> x >> y;

    move(1, 1);

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
