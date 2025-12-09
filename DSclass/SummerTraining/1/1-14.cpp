#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<string, int> mp;
void solve() {
    string s1, s2;
    int l, r, num, num1;
    cin >> s1 >> s2 >> l >> r;

    if (mp[s1] > mp[s2]) {
        num = 8 - mp[s1] + mp[s2];
    } else if (mp[s1] < mp[s2]) {
        num = mp[s2] - mp[s1] + 1;
    } else {
        num = 1;
    }

    int cnt = 0;
    while (num <= r) {
        if (num >= l) cnt++;
        if (cnt == 1) num1 = num;
        if (cnt == 2) break;
        num += 7;
    }

    if (cnt == 1) {
        cout << num1 << '\n';
    } else if (cnt == 0) {
        cout << "impossible" << '\n';
    } else {
        cout << "many" << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    mp["monday"] = 1;
    mp["tuesday"] = 2;
    mp["wednesday"] = 3;
    mp["thursday"] = 4;
    mp["friday"] = 5;
    mp["saturday"] = 6;
    mp["sunday"] = 7;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
