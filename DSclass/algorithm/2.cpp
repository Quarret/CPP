#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    int s, v, t, flag;
};


void solve() {
    int N, K;
    cin >> N >> K;
    vector<node> a(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> a[i].s;
    }
    
    for (int i = 1; i <= N; i++) {
        cin >> a[i].v;
    }

    vector<node> inj;
    
    a[K].flag = 1;
    inj.push_back(a[K]);

    while (!inj.empty()) {
        for (int i = 1; i < N; i++) {
            if (a[i].flag == 0) {
                if (a[i].s < inj.back().s && a[i].v > inj.back().v && (inj.back().s - a[i].s) % (a[i].v - inj.back().v) == 0 && inj.back().t <= (inj.back().s - a[i].s) / (a[i].v - inj.back().v)) {
                    a[i].t = (inj.back().s - a[i].s) / (a[i].v - inj.back().v);
                    a[i].flag = 1;
                    inj.push_back(a[i]);
                    //cout << i << '\n';
                }

                else if (a[i].s > inj.back().s && a[i].v < inj.back().v && (inj.back().s - a[i].s) % (a[i].v - inj.back().v) == 0 && inj.back().t <= (inj.back().s - a[i].s) / (a[i].v - inj.back().v)) {
                    a[i].t = (inj.back().s - a[i].s) / (a[i].v - inj.back().v);
                    a[i].flag = 1;
                    inj.push_back(a[i]);
                    //cout << i << '\n';
                }

                else if (a[i].s == inj.back().s) {
                    a[i].t = 0;
                    a[i].flag = 1;
                    inj.push_back(a[i]);
                    //cout << i << '\n';
                }
            }
        }

        inj.pop_back();
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (a[i].flag == 1) {
            ans++;
        }
    }

    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
