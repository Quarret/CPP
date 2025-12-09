#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[a[i]] != i) {
            cout << "no\n";
            return;
        }
    }

    cout << "yes\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    while (k--) {
        solve();
    }

    return 0;
}
