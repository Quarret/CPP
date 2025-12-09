#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    string name;
    string id;
    int num;
};
void solve() {
    int n;
    cin >> n;
    vector<node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].id >> a[i].num;
    }

    sort(a.begin(), a.end(), [&](node x, node y) {
        return x.num > y.num;
    });

    cout << a[0].name << ' ' << a[0].id << '\n';
    cout << a.back().name << ' ' << a.back().id << '\n';        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
