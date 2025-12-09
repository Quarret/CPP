#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    if (s1 == s2 && s2 == s3) {
        cout << "B\n";
    } else if (s2 == s3) {
        cout << "A\n";
    }  else if (s1 == s3) {
        cout << "B\n";
    }  else if (s1 == s2) {
        cout << "C\n";
    } 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
