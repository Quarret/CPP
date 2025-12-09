#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.size(), ans = 1, ex = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) ans++;
        if (s[i] == '0' && s[i + 1] == '1') {//10相邻就分，若有01少分一个
            ex = 1;
        }
    }

    cout << ans - ex << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
