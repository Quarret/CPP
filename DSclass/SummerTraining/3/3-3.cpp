#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s1, s2, tmp, ans;
    cin >> s1 >> s2;
    int num = stoi(s2), n = s1.size(), num1, num2;

    for (int i = 0; i < n; i++) {
        tmp.push_back(s1[i]);
        num1 = stoi(tmp);
        num2 = num1 / num;
        ans.push_back(num2 + '0');
        num2 = num1 % num;
        tmp = num2 + '0';
    }
    if (ans == "0") {
        cout << ans << ' ' << tmp << '\n';
        return;
    }

    while (1) {
        if (ans[0] == '0') {
            ans.erase(0, 1);
        } else break;
    }

    cout << ans << ' ' << tmp << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
