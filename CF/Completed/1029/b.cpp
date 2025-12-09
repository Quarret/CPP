/*** 
 * @Author: Quarret
 * @Date: 2025-06-09 12:27:38
 * @LastEditTime: 2025-06-09 12:51:13
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a1, a2;

    int m = n / 2, num1 = 1, num2 = n;

    if (n == 3) {
        cout << "1 3 2" << '\n';
        return;
    }

    while (num1 < num2) {
        a1.push_back(num1);
        a2.push_back(++num1);
        num1++;
        if (num1 + 1 < num2) {
            a2.push_back(num2);
            a1.push_back(--num2);
            num2--;
        }
    }

    if (n % 2) a1.push_back(num1);

    for (auto& x: a1) cout << x << ' ';
    reverse(a2.begin(), a2.end());
    for (auto& x: a2) cout << x << ' ';
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
