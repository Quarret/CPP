#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, ans;
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '.') {
            ans.push_back(s[i]);
        }
    }

    cout << ans << '\n';

    return 0;
}
