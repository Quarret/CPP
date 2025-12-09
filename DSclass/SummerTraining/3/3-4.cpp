#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;

    int maxx = 0, minn = 0, sum = 0, num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        minn = min(minn, sum);
        maxx = max(maxx, sum);
    }

    int num1 = w - maxx, num2 = abs(minn);
    if (num1 - num2 + 1 <= 0) {
        cout << 0 << '\n';
    } else {
        cout << num1 - num2 + 1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
