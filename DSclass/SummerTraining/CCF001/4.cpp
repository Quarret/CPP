#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, tmp;
    cin >> n;

    vector< vector<int> > nxt(n), bef(n);
    vector< vector<int> > up(n), down(n);


    for (int i = 1; i <= n - 1; i++) {
        cin >> tmp;
        nxt[i].push_back(tmp);
        bef[tmp].push_back(i);
    }

    int m;
    cin >> m;
    queue<int> q;
    vector<bool> ins(n, 0);

    for (int i = 0; i < n; i++) {
        set<int> st;
        q.push(i);

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            for (auto& e: bef[tmp]) {
                q.push(e);
                st.insert(e);
            }
        }

        for (auto& it: st) {
            up[i].push_back(it);
        }
        up[i].push_back(i);

        st.clear();
        q.push(i);

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            for (auto& e: nxt[tmp]) {
                q.push(e);
                st.insert(e);
            }
        }

        for (auto& it: st) {
            down[i].push_back(it);
        }
        down[i].push_back(i);

        //cout << up[i].size() << ' ' << down[i].size() << '\n';
    }

    while (m--) {
        string s;
        int num, ans = 0;
        cin >> s >> num;

        if (s == "uninstall") {
            for (auto& u : up[num]) {
                if (ins[u]) ans++;
                ins[u] = 0;
            }
        } else {
            for (auto& u : down[num]) {
                if (!ins[u]) ans++;
                ins[u] = 1;
            }
        }

        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
