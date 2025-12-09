#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    string tmp = to_string(n);

    for (int i = 1; i <= m; i++) {
        if (i % n == 0) {
            cout << i << ' ';
            continue;;
        }
        
        string s = to_string(i);
        if(s.find(tmp, 0) >= 0 && s.find(tmp, 0) < s.size()) {
            cout << i << ' ';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
