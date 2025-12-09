#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    int win = 0;
    int ping = 0;
    int lose = 0;
    int a[3] = {0};
    char ans;
};
void solve() {
    int n, maxn1 = -1, maxn2 = -1;
    char c1,c2;
    cin >> n;
    node n1, n2;

    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        if (c1 == 'B' && c2 == 'B') {
            n1.ping++;
            n2.ping++;
        } else if (c1 == 'B' && c2 == 'C') {
            n1.win++;
            n2.lose++;
            n1.a[0]++;
        } else if (c1 == 'B' && c2 == 'J') {
            n1.lose++;
            n2.win++;
            n2.a[2]++;
        } else if (c1 == 'C' && c2 == 'B') {
            n1.lose++;
            n2.win++;
            n2.a[0]++;
        } else if (c1 == 'C' && c2 == 'C') {
            n1.ping++;
            n2.ping++;
        } else if (c1 == 'C' && c2 == 'J') {
            n1.win++;
            n2.lose++;
            n1.a[1]++;
        } else if (c1 == 'J' && c2 == 'B') {
            n1.win++;
            n2.lose++;
            n1.a[2]++;
        } else if (c1 == 'J' && c2 == 'C') {
            n1.lose++;
            n2.win++;
            n2.a[1]++;
        } else if (c1 == 'J' && c2 == 'J') {
            n1.ping++;
            n2.ping++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (n1.a[i] > maxn1) {
           if (i == 0) n1.ans = 'B';
           else if (i == 1) n1.ans = 'C';
           else n1.ans = 'J';
           maxn1 = n1.a[i];
        }

        if (n2.a[i] > maxn2) {
           if (i == 0) n2.ans = 'B';
           else if (i == 1) n2.ans = 'C';
           else n2.ans = 'J';
           maxn2 = n2.a[i];  
        }
    }

    cout << n1.win << ' ' << n1.ping << ' ' << n1.lose << '\n';
    cout << n2.win << ' ' << n2.ping << ' ' << n2.lose << '\n';
    cout << n1.ans << ' ' << n2.ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
