#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    ll ans = 0, pos = 0;
    while (s.find("ABC", pos) != -1) {
        ans++;
        pos = s.find("ABC", pos) + 1;
    }
    //cout << ans << '\n';

    while (q--) {
        int x;

        char c;
        cin >> x >> c;
        x--;

        if (x + 1 < n && x + 2 < n) {
            if (s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C' && c != s[x]) {
                ans--;
            }

            if (c == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C' && c != s[x]) {
                ans++;
            } 
        }
        
        if (x - 1 >= 0 && x + 1 < n) {
            if (s[x - 1] == 'A' && s[x] == 'B' && s[x + 1] == 'C' && c != s[x]) {
                ans--;
            }

            if (s[x - 1] == 'A' && c == 'B' && s[x + 1] == 'C'  && c != s[x]) {
                ans++;
            }
            
        }
        
        if (x - 2 >= 0 && x -1 >= 0) {
            if (s[x - 2] == 'A' && s[x - 1] == 'B' && s[x] == 'C' && c != s[x])  {
                ans--;
            } 
            
            if (s[x - 2] == 'A' && s[x - 1] == 'B' && c == 'C'  && c != s[x]) {
                ans++;
            }
        }

        s[x] = c;

        cout << ans << '\n';
    }

    return 0;
}
