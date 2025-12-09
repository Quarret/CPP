#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int num1 = a % 2, num2 = b % 2;

    if (num1 == 0 && num2 == 0) {
        cout << "Yes" << '\n';
        return;
    }

    if (num1 == 0 && num2 == 1 && a >= 2) {
        cout << "Yes" << '\n';
        return;
    }

    cout << "No" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        solve();    
    }
    

    return 0;
}
