#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    string s;
    int cnt;
    int num;
};
bool cmp(node x, node y) {
    if (x.cnt < y.cnt) {
        return 1;
    } else if (x.cnt == y.cnt) {
        return x.num < y.num;
    } else return 0;
}
void solve() {
    int n, m, num;
    cin >> n >> m;

    vector<node> a;

    while (m--) {
        num++;
        string s;
        cin >> s;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] < s[i]) {
                    cnt++;
                }
            }
        }
        
        node tmp;
        tmp.s = s;
        tmp.cnt = cnt;
        tmp.num = num;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < num; i++) {
        cout << a[i].s << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
