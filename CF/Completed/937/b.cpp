#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                if (i % 2) {
                    cout << "##";
                } else {
                    cout << "..";
                }
            }

            cout << endl;

            for (int i = 1; i <= n; i++) {
                if (i % 2) {
                    cout << "##";
                } else {
                    cout << "..";
                }
            }

            cout << endl;
        } else {
           for (int i = 1; i <= n; i++) {
                if (i % 2) {
                    cout << "..";
                } else {
                    cout << "##";
                }
            }

            cout << endl;

            for (int i = 1; i <= n; i++) {
                if (i % 2) {
                    cout << "..";
                } else {
                    cout << "##";
                }
            }

            cout << endl; 
        }
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
