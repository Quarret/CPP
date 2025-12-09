#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a1[105][105], b1[105][105];
void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    //cout << n << ' ' << m << ' ' << t << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a1[i][j];
            //cout << a1[i][j] << ' ';
        }
        //cout << '\n';
    }

    int op, a, b;
    while (t--) {
        cin >> op >> a >> b;
        //cout << op << ' ' << a << ' ' << b << '\n';
        if (op == 1) {
            vector<int> a2;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a2.push_back(a1[i][j]);
                }
            }

            int num = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    a1[i][j] = a2[num++];
                }
            }
            n = a, m = b;
        } else if (op == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b1[j][i] = a1[i][j];
                }
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    a1[i][j] = b1[i][j];
                }
            }
            int tmp = n;
            n = m;
            m = tmp;
        } else {
            cout << a1[a][b] << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
