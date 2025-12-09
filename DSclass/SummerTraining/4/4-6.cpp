#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<int, string> mp;
vector<int> w = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
void solve() {
    string s;
    while (cin >> s) {
        if (s == "-1") {
            return;
        }
        
        ll sum = 0;

        for (int i = 0; i < 17; i++) {
            sum += w[i] * (s[i] - '0');
        }

        string tmp;
        tmp.push_back(s[17]);

        int y = sum % 11;

        if (mp[y] == tmp) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp[0] = "1";
    mp[1] = "0";
    mp[2] = "X";
    mp[3] = "9";
    mp[4] = "8";
    mp[5] = "7";
    mp[6] = "6";
    mp[7] = "5";
    mp[8] = "4";
    mp[9] = "3";
    mp[10] = "2";

    solve();
}
