#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<int, int> mp;
void solve() {
    int num1, num2;

    while (cin >> num1 >> num2) {
        //cout << num1 << ' ' << num2 << '\n';
        mp[num1] += num2;
    }

    vector<pair<int, int>> a(mp.begin(), mp.end());
    sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y) {
        return x.first > y.first;
    });

    for (int i = 0; i < a.size(); i++) {
        if (a[i].second) {
        cout << a[i].first << ' ' << a[i].second << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
