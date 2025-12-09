#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s, tmp;
    cin >> s;
    s.push_back('.');

    vector<int> a;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
           a.push_back(stoi(tmp));
           //cout << stoi(tmp) << '\n';
           tmp.clear();
           continue;
        }
        tmp.push_back(s[i]); 
    }

    int  ans = 0;
    for (int i = 0; i < 4; i++) {
        int num = 256;
        while (num) {
            if (a[i] / num) {
                a[i] %= num;
                ans++;
            }
            num /= 2;
        }
    }

    cout << ans << '\n'; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
