#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    char c[] = {'a', 'e', 'i', 'o', 'u'};

    int num = n / 5, num1 = n % 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < num; j++) {
            cout << c[i];
        }

        if (num1 > 0) {
            cout << c[i];
            num1--;
        }
    }

    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
