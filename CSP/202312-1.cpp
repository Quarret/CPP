#include <bits/stdc++.h>
using namespace std;
int n, m, num;

struct node{
        int id;
        vector<int> a;
        int ans = 1e9;
};
vector<node> v;
void solve() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        node node1;
        node1.id = i;
        for(int j = 0; j < m; j++) {
            cin >> num;
            node1.a.push_back(num);
        }
        v.push_back(node1);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            bool flag = 1;
            for(int h = 0; h < m; h++) {
                if(v[i].a[h] >= v[j].a[h]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                v[i].ans = min(v[i].ans, v[j].id);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        //cout << v[i].a[1] << ' ';
        if(v[i].ans == 1e9) cout << 0 << '\n';
        else cout << v[i].ans << '\n';
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
;}
