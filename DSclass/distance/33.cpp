#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    queue<int> q;
    vector<int> v;
    vector< queue<int> > vq;
    int num, nowout = 1;
    while (cin >> num) {
        v.push_back(num);
    }
    for (int i = v.size(); i >= 0; i--) {
        q.push(v[i]);
    }

    while (q.size()) {
        int maxx = -1e9, pos = -1;
        for (int i = 0; i < vq.size(); i++) {
            if(nowout == q.front()) {
                q.pop();
                nowout++;
                break;
            } else if (nowout == vq[i].front()) {
               q.pop();
               vq[i].pop();
               nowout++;
               break;
            } else {
              for (int j = 0; j < vq.size(); j++) {
                if (vq[j].back() < q.front()) {
                    if (vq[j].back() > maxx) {
                        maxx = vq[j].back();
                        pos = j;
                    }
                }
              }
              if (pos == -1) {
                queue<int> temp;
                temp.push(q.front());
                vq.push_back(temp);
                q.pop();
              } else {
              vq[pos].push(q.front());
              q.pop();
              }
              break;  
            }
        }

        if (vq.size() == 0) {
            queue<int> temp;
            vq.push_back(temp);
            if (q.front() == nowout) {
                q.pop();
            } else {
                vq[0].push(q.front());
                q.pop();
            }
        }
    }

    cout << vq.size()<< '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}