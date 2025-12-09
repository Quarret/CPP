#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int n1 = s1.size(), n2 = s2.size();
    int pos1 = s1.find('.'), pos2 = s1.rfind('.');
    int pos3 = s2.find('.'), pos4 = s2.rfind('.');

    int g1 = stoi(s1.substr(0, pos1)), 
    sk1 = stoi(s1.substr(pos1 + 1, pos2 - pos1)), 
    k1 = stoi(s1.substr(pos2 + 1, n1 - pos2));

    int g2 = stoi(s2.substr(0, pos3)), 
    sk2 = stoi(s2.substr(pos3 + 1, pos4 - pos3)), 
    k2 = stoi(s2.substr(pos4 + 1, n2 - pos4));
    
    int g3, sk3, k3;
    ll sum1 = g1 * 17 * 29 + sk1 * 17 + k1, sum2 = g2 * 17 * 29 + sk2 * 17 + k2;
    if (sum1 <= sum2) {
        if (k2 < k1) {
            sk2--;
            k3 = k2 + 29 - k1;
        } else k3 = k2 - k1;

        if (sk2 < sk1) {
            g2--;
            sk3 = sk2 + 17 - sk1;
        } else sk3 = sk2 - sk1;

        g3 = g2 - g1;

        cout << g3 << '.' << sk3 << '.' << k3 << '\n';
    } else {
        if (k1 < k2) {
            sk1--;
            k3 = k1 + 29 - k2;
        } else k3 = k1 - k2;

        if (sk1 < sk2) {
            g1--;
            sk3 = sk1 + 17 - sk2;
        } else sk3 = sk1 - sk2;

        g3 = g1 - g2;

        cout << '-' << g3 << '.' << sk3 << '.' << k3 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
