#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll N, A, B, C;
void solve() {
    vector<int> a(N);
    string s;
    ll L = 0, Y = 0, F = C, cnt = 1;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s[0] == 'G') {
            a[i] = s[1] - '0';
        }
    }

    while (1) {
        F = ((A % 6) * (F % 6)) % 6 + (B % 6) + 1;
        if (cnt % 2 == 0) {
            Y += F;
            if (Y >= N) {
                Y = (N - 1) - (Y % (N - 1));
            }

            if (Y == L) {
                L = 0;
            }

            if (Y == N - 1) {
                cout << "Yueyue" << '\n';
                return;
            }   

            while (a[Y] != 0) {
                Y = a[Y];
                if (Y >= N)
                {
                    Y = (N - 1) - (Y % (N - 1));
                }

                if (Y == L) {
                    L = 0;
                }

                if (Y == N - 1) {
                cout << "Yueyue" << '\n';
                return;
            }
            }
            //cout << "Y : " << Y << ' ' << F << '\n';
        } else {
            L += F;
            if (L >= N) {
                L = (N - 1) - (L % (N - 1));
            }

            if (Y == L) {
                Y = 0;
            }

            if (L == N - 1) {
                cout << "Lele" << '\n';
                return;
            }   

            while (a[L] != 0) {
                L = a[L];
                if (L >= N)
                {
                    L = (N - 1) - (L % (N - 1));
                }

                if (Y == L) {
                    Y = 0;
                }

                if (L == N - 1) {
                cout << "Lele" << '\n';
                return;
            }
            }
            //cout << "L : " << L << ' ' << F << '\n';
        }
        cnt++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    while (cin >> N >> A >> B >> C) {
        solve();
    }
}
