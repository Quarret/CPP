#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s, tmp;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            reverse(tmp.begin(), tmp.end());
            cout << tmp << ' ';
            tmp.clear();
        }
        if (s[i] != ' ') tmp.push_back(s[i]);
        
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    n++;
    while (n--) {
        solve();
    }
}
