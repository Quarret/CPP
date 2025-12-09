#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<char, int> mp1;
map<string, int> mp2;
void solve() {
    int n;
    cin >> n;
    string tmp,s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
        if (s[j] >= '0' && s[j] <= '9') {
            tmp.push_back(s[j]);
        } else  if (s[j] != '-') {
            tmp.push_back(mp1[s[j]]);
        }
        }

        mp2[tmp]++;
        tmp.clear();
    }

    for (auto &it: mp2) {
        if (it.second > 1) {
            tmp = it.first;
            tmp.insert(3, 1, '-');
            cout << tmp << ' ' << it.second << '\n';
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    
    mp1['A'] = '2';
    mp1['B'] = '2';
    mp1['C'] = '2';
    mp1['D'] = '3';
    mp1['E'] = '3';
    mp1['F'] = '3';
    mp1['H'] = '4';
    mp1['I'] = '4';
    mp1['G'] = '4';
    mp1['J'] = '5';
    mp1['K'] = '5';
    mp1['L'] = '5';
    mp1['M'] = '6';
    mp1['N'] = '6';
    mp1['O'] = '6';
    mp1['P'] = '7';
    mp1['R'] = '7';
    mp1['S'] = '7';
    mp1['T'] = '8';
    mp1['U'] = '8';
    mp1['V'] = '8';
    mp1['W'] = '9';
    mp1['X'] = '9';
    mp1['Y'] = '9';
    
    solve();
}
