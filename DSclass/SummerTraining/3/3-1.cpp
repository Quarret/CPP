#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string A, B, a, b, ans;
    char DA, DB;
    cin >> A >> DA >> B >> DB;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == DA) {
            a += DA;
        }
    }

    for (int j = 0; j < B.size(); j++) {
        if (B[j] == DB) {
            b += DB;
        }
    }
    
    if (a == "" && b == "") {
        cout << 0 << '\n';
        return;
    }
    int num = 0, flag = 0;
    if (a.size() > b.size()) {
        for (int i = 0; i < b.size(); i++) {
            num = a[i] - '0' + b[i] - '0' + flag;
            //cout << num << '\n';
            flag = num / 10;
            num %= 10;
            ans += num + '0';
        }

        for (int i = b.size(); i < a.size(); i++) {
            num = a[i] - '0' + flag;
            //cout << num << '\n';
            flag = num / 10;
            num %= 10;
            ans += num + '0';
        }

        if (!flag) num += flag + '0';
    } else {
        for (int i = 0; i < a.size(); i++) {
            num = a[i] - '0' + b[i] - '0' + flag;
            //cout << num << '\n';
            flag = num / 10;
            num %= 10;
            ans += num + '0';
        }

        for (int i = a.size(); i < b.size(); i++) {
            num = b[i] - '0' + flag;
            //cout << num << '\n';
            flag = num / 10;
            num %= 10;
            ans += num + '0';
        }

        if (!flag) num += flag + '0';
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
