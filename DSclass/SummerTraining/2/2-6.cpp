#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<char, int> mp1;
map<int, char> mp2;
void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    vector<char> a;
    int n1 = s1.size(), n2 = s2.size();

    int num = 0, num1 = 0;
    char x;
    for (int i = 0; i < min(n1, n2); i++) {
        num1 = mp1[s1[i]] + mp1[s2[i]] + num;
        num = num1 / 26;
        x = mp2[num1 %= 26];
        a.push_back(x); 
    }
    
    if (n1 <= n2) {
        for (int i = n1; i < n2; i++) {
            num1 = mp1[s2[i]] + num;
            num = num1 / 26;
            x = mp2[num1 % 26];
            a.push_back(x);
        }
    } else {
        for (int i = n2; i < n1; i++) {
            num1 = mp1[s1[i]] + num;
            num = num1 / 26;
            x = mp2[num1 % 26];
            a.push_back(x);
        }
    }
    if (num) {
    x = mp2[num];
    a.push_back(x);
    }

    string ans;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    
    for (int i = 97; i <= 122; i++) {
        mp1[(char)i] = i - 97;
    }

    for (int i = 0; i <= 25; i++) {
        mp2[i] = (char)(i + 97);
    }
    

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
