#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
vector<int> a = {31, 28, 31, 30, 31, 30 ,31, 31, 30, 31 ,30 ,31}, b = {31, 29, 31, 30, 31, 30 ,31, 31, 30, 31 ,30 ,31};
void solve() {
    int y = 2000, m = 1, d, flag = 0;

    while (1) {
        if (y % 4 == 0) {
            if (y % 100 == 0 && y % 400 != 0) {
                if (n > 365) {
                    n -= 365;
                    y++;
                } else {
                    flag = 0;
                    break;
                }
            } else {
                if (n > 366) {
                    n -= 366;
                    y++;
                } else {
                    flag = 1;
                    break;
                }
            }
        } else {
            if (n > 365) {
                n -= 365;
                y++;
            } else {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1) {
        for (int i = 0; i < 12; i++) {
            if (n > b[i]) {
                n -= b[i];
                m++;
            } else {
                d = n;
                break;
            }
        }
    } else {
        for (int i = 0; i < 12; i++) {
            if (n > a[i]) {
                n -= a[i];
                m++;
            } else {
                d = n;
                break;
            }
        }
    }
    
    cout << y << '-' << setw(2) << setfill('0') << m << '-' << setw(2) << setfill('0') << d <<' ';

    if (m == 1 || m == 2) {
        y--, m += 12;
    }
    int c = y / 100;
    int y1 = y - c * 100;
    int week = y1 + y1 / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    while (week < 0)
        week += 7;
    week %= 7;
    switch (week)
    {
    case 1:
        cout << "Monday\n";
        break;
    case 2:
        cout << "Tuesday\n";
        break;
    case 3:
        cout << "Wednesday\n";
        break;
    case 4:
        cout << "Thursday\n";
        break;
    case 5:
        cout << "Friday\n";
        break;
    case 6:
        cout << "Saturday\n";
        break;
    case 0:
        cout << "Sunday\n";
        break;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> n;
        if (n == -1) return 0;
        n = n + 1;

        solve();
    }
}
