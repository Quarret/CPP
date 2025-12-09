#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    string s1 = s.substr(0, 2);
    string s2 = s.substr(3, 2);
    int num1 = stoi(s1), num2 = stoi(s2);

    if (num1 < 12) {
        if (num1 == 0) {
            cout << setw(2) << setfill('0') << num1 + 12 << ':' << setw(2) << setfill('0') << num2 << ' ' << "AM" << '\n';
        } else {
        cout << setw(2) << setfill('0') << num1 << ':' << setw(2) << setfill('0') << num2 << ' ' << "AM" << '\n';
        }
    } else if (num1 == 12) {
        cout << setw(2) << setfill('0') << num1 << ':' << setw(2) << setfill('0') << num2 << ' ' << "PM" << '\n';
    } else {
        cout << setw(2) << setfill('0') << num1 - 12 << ':' << setw(2) << setfill('0') << num2 << ' ' << "PM" << '\n';
    }
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
