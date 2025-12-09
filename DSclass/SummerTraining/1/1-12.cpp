#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    int id;
    int cur = 0;
    int cap = 0;
};
void solve() {
    int t, m, n, x, cnt = 1;
    string s;
    cin >> t >> m;
    //cout << t << ' ' << m << '\n';

    vector<node> a;
    node n1;
    n1.cur = 0;
    n1.id = 0;
    n1.cap = m;
    a.push_back(n1);

    while (t--) {
        cin >> s;
        //cout << s << ' ';
        if (s == "alloc") {
            cin >> n;
            //cout << n << '\n';
            for (int i = 0; i < a.size(); i++) {
                if (n <= a[i].cap - a[i].cur) {
                    if (a[i].id == 0) {
                        node n2;
                        n2.id = cnt;
                        n2.cap = n;
                        n2.cur = n;
                        a.back().cap -= n;
                        a.insert(a.end() - 1, n2);
                        cout << cnt << '\n';
                        cnt++;
                        break;
                    } else {
                        node n2;
                        n2.id = cnt;
                        n2.cap = n;
                        n2.cur = n;
                        a[i].cap -= n;
                        a.insert(a.begin() + i, n2);
                        cout << cnt << '\n';
                        cnt++;
                        break;
                    }
                }
                if (i == a.size() - 1) {
                    cout << "NULL" << '\n';
                }
            }
        } else if (s == "erase") {
            cin >> x;
            //cout << x << '\n';
            for (int i = 0; i < a.size(); i++) {
                if (a[i].id == x && a[i].cur != 0) {
                    a[i].cur = 0;
                    break;
                } else if (i == a.size() - 1) {
                    cout << "ILLEGAL_ERASE_ARGUMENT" << '\n';
                }
            }
        } else {
            //cout << '\n';
            int num = 0;
            for (int i = 0; i < a.size() - 1; i++) {
                if (a[i].cur < a[i].cap) {
                    num += a[i].cap - a[i].cur;
                    a[i].cap = a[i].cur;
                }
            }
            a.back().cap += num;
        }
    } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
