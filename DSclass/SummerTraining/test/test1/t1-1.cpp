#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, num = 0;
    cin >> n;
    string s;
    cin >> s;
    char x;
    int a[3][3];

flag: while (n--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> x;
                a[i][j] = x - '0';
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 3; i++) {
            cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == 1) {
                    cnt1++;
                } else if (a[i][j] == 2) {
                    cnt2++;
                }
            }

            if (cnt1 == 3) {
                cout << s[num++] << '\n';
                goto flag;
            } else if (cnt2 == 3) {
                if (s[num] == 'A') {
                    cout << 'B' << '\n';
                    num++;
                    goto flag;
                } else {
                    cout << 'A' << '\n';
                    num++;
                    goto flag;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < 3; j++) {
                if (a[j][i] == 1) {
                    cnt1++;
                } else if (a[j][i] == 2) {
                    cnt2++;
                }
            }

            if (cnt1 == 3) {
                cout << s[num++] << '\n';
                goto flag;
            } else if (cnt2 == 3) {
                if (s[num] == 'A') {
                    cout << 'B' << '\n';
                    num++;
                    goto flag;
                } else {
                    cout << 'A' << '\n';
                    num++;
                    goto flag;
                }
            }
        }
        
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i][i] == 1) {
                cnt1++;
            } else if (a[i][i] == 2) {
                cnt2++;
            }
        }

        if (cnt1 == 3) {
            cout << s[num++] << '\n';
            goto flag;
        } else if (cnt2 == 3) {
            if (s[num] == 'A') {
                cout << 'B' << '\n';
                num++;
                goto flag;
            } else {
                cout << 'A' << '\n';
                num++;
                goto flag;
            }
        }
        
        cnt1 = 0, cnt2 = 0; 
        for (int i = 0; i < 3; i++) {
            if (a[i][2 - i] == 1) {
                cnt1++;
            } else if (a[i][2 - i] == 2) {
                cnt2++;
            }
        }

        if (cnt1 == 3) {
            cout << s[num++] << '\n';
            goto flag;
        } else if (cnt2 == 3) {
            if (s[num] == 'A') {
                cout << 'B' << '\n';
                num++;
                goto flag;
            } else {
                cout << 'A' << '\n';
                num++;
                goto flag;
            }
        }  
    }

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
