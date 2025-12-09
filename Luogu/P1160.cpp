#include <bits/stdc++.h>
using namespace std;

using it = list<int>::iterator;

int n, k, p, m, num;
list<int> l;
void solve() {
    cin >> n;
    l.emplace_back(1);
    it pos[100005];
    pos[1] = l.begin();
    for(int i = 2; i <= n; i++) {
        cin >> k >> p;

        if(!p) {
            pos[i] = l.insert(pos[k], i);
            //pos[k] = next(pos[k]);
        } else {
            pos[i] = l.insert(next(pos[k]), i);
        }
        
    }

    cin >> m;
    int a[100005] = {0};
    //cout << '\n';
    while(m--) {
        cin >> num;
        a[num]++;
    }
    
    for(auto it1 = l.begin(); it1 != l.end(); it1++) {
        if(!a[*it1]) {
            cout << *it1 << ' ';
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
