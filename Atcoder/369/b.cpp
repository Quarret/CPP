#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    vector<int> a, b;
    int n, num;
    char op;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num >> op;
        if (op == 'L') {
            a.push_back(num);
        } else {
            b.push_back(num);
        }
    }

    int ans = 0;

    if (!a.empty()) {
        int num1 = a.front();
        for (int i = 1; i < a.size(); i++) {
            ans += abs(a[i] - num1);
            num1 = a[i];
        }
    }

    if (!b.empty()) {
        int num2 = b.front();
        
        for (int i = 1; i < b.size(); i++) {
            ans += abs(b[i] - num2);
            num2 = b[i];
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
