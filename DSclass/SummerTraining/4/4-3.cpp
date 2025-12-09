#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    string s;
    cin >> s;
    int pos = 0, cnt1 = 0, cnt2 = 0;
    while (s.find("ab", pos) != -1) {
        cnt1++;
        pos = s.find("ab", pos) + 1;
    }
    
    pos = 0;
    while (s.find("ba", pos) != -1) {
        cnt2++;
        pos = s.find("ba", pos) + 1;
    }

    cout << cnt1 - cnt2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> n;
        if (!n) return 0;

        solve();
    }
}
