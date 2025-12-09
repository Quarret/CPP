#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    int id;
    int t;
    int score;
};
void solve() {
    int n;
    cin >> n;
    //cout << n << '\n';

    vector<node> a(n), b;

    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].score;
        //cout << a[i].t << ' ' << a[i].score << '\n';
        a[i].id = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (a[j].t < a[i].t && a[j].score > a[i].score) {
                break;
            } else if (a[j].t == a[i].t && a[j].score > a[i].score) {
                break;
            } else if (a[j].t < a[i].t && a[j].score == a[i].score) {
                break;
            }

            if (j == n - 1) {
                b.push_back(a[i]);
            }
        }
    }
    
    sort(b.begin(), b.end(), [&](node x, node y) {
        return x.id < y.id;
    });
    for (int i = 0; i < b.size(); i++) {
        cout << b[i].id << '\n';
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
