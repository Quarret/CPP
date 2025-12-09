#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    vector<int> q, temp, v;
    vector< vector<int> > vq;
    int num, nowout = 1;
    while (cin >> num) {
        v.push_back(num);
    }
    //num = *max_element(v.begin(), v.end());
    /*for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';*/
    
    for (int i = v.size() - 1; i >= 0; i--) {
        q.push_back(v[i]);
    }

    vq.push_back(temp);

FlagA: while (q.size() != 1) {
    if (q.size() != 0 ) {
        if (nowout == q.front() ) {
                q.erase(q.begin());
                nowout++;
                goto FlagA;
        }
    }
         
        for (int i = 1; i < vq.size(); i++) {
            if (vq.size() != 0 ) {
           if (nowout == vq[i].front()) {
               vq[i].erase(vq[i].begin());
               nowout++;
               goto FlagA;
            }
            }
        }
        
        
        int maxx = -1e9, pos = -1;
        for (int i = 1; i < vq.size(); i++) {
            if (vq[i].back() < q.front() && vq[i].back() > maxx) {
                maxx = vq[i].back();
                pos = i;
               }
            }

            if (pos == -1) {
            vector<int> temp;
            temp.push_back(q.front());
            q.erase(q.begin());
            vq.push_back(temp);
            } else {
            vq[pos].push_back(q.front());
            q.erase(q.begin());
            }
        }

        cout << vq.size() << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
