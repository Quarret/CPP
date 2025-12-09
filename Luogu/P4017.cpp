#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int MOD = 80112002, ans = 0;
void solve() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> out(n + 1), in(n + 1), l(n + 1);
    vector< vector<int> > nxt(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        nxt[a].push_back(b);
        out[a]++;
        in[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
            l[i] = 1;
        }
    }
    
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (auto &it: nxt[tmp]) {
            l[it] += l[tmp];
            cout << l[it] << ' ';
            l[it] %= MOD;
            in[it]--;
            out[tmp]--;

            if (!in[it]) {
                if (!out[it]) {
                    ans += l[it];
                    ans %= MOD;
                }

                q.push(it);
            }
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}



// C:\\Program Files\\mingw64\\bin\\gdb.exe
// C:\\Program Files\\mingw64\\bin\\gcc.exe