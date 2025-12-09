#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int num = 0, flag = 0, n = 0;
string s;
int vis[1 << 20]{};
void dfs(int val) {
    if (val == 0) {
        flag = 1;
        return; 
    }
    if (s[val - 1] != '0' || flag == 1) return;
    vis[val] = 1;

    for (int i = 0; i < n; i++) {
        if ((val & (1 << i)) != 0 && !vis[val ^ (1 << i)]) {
            dfs(val ^ (1 << i));
        }
    }
};
void solve() { 
    cin >> n;
    cin >> s;

    flag = 0;
    num = 0;
    memset(vis, 0, 1 << n);

    for (int i = 0; i < n; i++) num |= (1 << i);
    
    dfs(num);

    cout << (flag ? "Yes" : "No") << '\n';
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
