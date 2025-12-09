#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int pos = s.find('#');
        //cout << pos << '\n';

        ans.push_back(pos + 1);
    }

    reverse(ans.begin(), ans.end());

    for (auto& it : ans) {
        cout << it << ' ';
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
