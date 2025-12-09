#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int k, n, num = 0;
    cin >> k;
    //cout << k << '\n';
    vector<int> a;

    string s;
    cin >> s;
    //cout << s << '\n';

    for (int i = 0; i < s.size(); i++) {
        num += s[i] - '0';
        a.push_back(s[i] - '0');
    }

    sort(a.begin(), a.end());

    if (num >= k) {
        cout << 0 << '\n';
        return;
    }

    int num1 = k - num, num2 = 0;
    for (int i = 0; i < a.size(); i++) {
        num2 += 9 - a[i];
        if (num2 >= num1) {
            cout << i + 1 << '\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
