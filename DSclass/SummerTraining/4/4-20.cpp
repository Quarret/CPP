#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    int num;
    int id;
    int num1;
};

void solve() {
    int n;
    cin >> n;

    vector<node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].num;
        a[i].num1 = i;
    }

    sort(a.begin(), a.end(),[&](node x, node y) {
        return x.num > y.num;
    });

    int cnt = 1;
    a[0].id = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1].num != a[i].num) {
            cnt++;
            a[i].id = cnt;
        } else {
            a[i].id = cnt;
        }
    }

    sort(a.begin(), a.end(), [&](node x, node y) {
        return x.num1 < y.num1;
    });

    for (auto &it : a) {
        cout << it.id << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
