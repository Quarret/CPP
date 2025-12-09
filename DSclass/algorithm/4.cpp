#include <bits/stdc++.h>
#define ll long long
using namespace std;

double Q;
int N;
void solve() {
    int m;
    double ans = 0.;
    vector<double> w;
    w.push_back(0.);
    while (N--) {
        cin >> m;
        double num1 = 0;
        vector<double> a(3);
        while (m--) {
            string s;
            cin >> s;
            
            char x;
            x = s[0];
            if (x != 'A' && x != 'B' && x != 'c') {
                break;
            }

            double num = stod(s.substr(2, s.size() - 2));

            if (x == 'A') {
                a[0] += num;
                num1 += num;
                if (a[0] > 600 || num > 1000) {
                    break;
                }
            } else if (x == 'B') {
                a[1] += num;
                num1 += num;
                if (a[1] > 600 || num > 1000) {
                    break;
                }
            } else {
                a[2] += num;
                num1 += num;
                if (a[2] > 600 || num > 1000) {
                    break;
                }
            }
        }
        w.push_back(num1);
    }

    vector< vector<double> > dp(w.size() + 1, vector<double>(100000));

    for (int i = 1; i <= w.size(); i++) {
        for (int j = 100000; j >= 0; j--) {
            if (j >= w[i] * 100) {
                dp[i][j] = max(dp[i - 1][j - w[i] * 100] + w[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[w.size() - 1][1000000] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    while (cin >> Q >> N) {
        if (!N) {
            return 0;
        }
        solve();
    }
}
