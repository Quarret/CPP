#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    int flag = 0;
    int pos1;
    int pos2;
};
void solve() {
    int n, m, k, id, num;
    cin >> n >> m >> k;
    string s;
    vector<int> a(n * n + 1);
    vector<node> b(m + 1);
    int N = n * n + 1;

    while (k--) {
        cin >> s;

        if (s == "in") {
            cin >> id >> num;
            if (b[id].flag == 1) {
                cout << "no\n";
                continue; 
            }

            int cnt = 0, pos;
            for (int i = 1; i < N; i++) {
                if (a[i] == 0) {
                    if (cnt == 0) {
                        pos = i;
                    }

                    cnt++;
                } else cnt = 0;

                if (cnt == num) {
                    for (int j = pos; j < pos + cnt; j++) {
                        a[j] = 1;
                    }
                    b[id].flag = 1;
                    b[id].pos1 = pos;
                    b[id].pos2 = pos + cnt -1;
                    //cout << b[id].pos1 << ' ' << b[id].pos2 << '\n';
                    cout << "yes\n";
                    break;
                }

                if (i == N - 1) {
                    cout << "no\n";
                }
            }
        } else {
            cin >> id;
            if (b[id].flag == 0) {
                cout << "no\n";
                continue;
            }

            for (int j = b[id].pos1; j <= b[id].pos2; j++) {
                a[j] = 0;
            }

            b[id].flag = 0;
            b[id].pos1 = 0;
            b[id].pos2 = 0;
            cout << "yes\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
