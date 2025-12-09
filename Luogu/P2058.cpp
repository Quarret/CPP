#include <bits/stdc++.h>
using namespace std;

int n, k, num, ans, a[100005];
struct node {
    int t;
    vector<int> a;
};
vector<node> v;

void solve() {
    cin >> n;
    //cout << n << '\n';
    while(n--) {
        node node1;
        cin >> node1.t >> k;
        //cout << node1.t << ' ' << k << '\n';
        for (int i = 0; i < k; i++) {
            cin >> num;
            node1.a.push_back(num);

            if (!a[num]) {
                ans++;
            }
            a[num]++;
        }
        v.push_back(node1);
        
        while(!(v[0].t > v.back().t -86400 && v[0].t <= v.back().t)) {
            for (int i = 0; i < v[0].a.size(); i++) {
                a[v[0].a[i]]--;
                if (a[v[0].a[i]] == 0) {
                    ans--;
                }
            }

            v.erase(v.begin());
        }
        
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
