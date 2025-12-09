#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
大多数dfs能够解决的问题，bfs也可以解决，来写bfs
*/
void solve() { 
    int n;
    string s;
    cin >> n >> s;
    //vector<int> vis((1 << 20), 0); TLE!!!
    vector<int> vis((1 << n), 0);

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int val = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            int v = val | (1 << i);
            if (s[v - 1] == '0' && !vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    cout << (vis[(1 << n) - 1] ? "Yes" : "No") << '\n'; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
