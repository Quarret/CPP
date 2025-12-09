#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, mg, u, v;
    cin >> n >> mg;

    vector G(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < mg; i++) {
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    int mh;
    cin >> mh;
    vector H(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < mh; i++) {
        cin >> u >> v;
        H[u][v] = 1;
        H[v][u] = 1;
    }

    vector A(n + 1, vector<int>(n + 1, 0));

    vector P(n + 1, 0);
    // for (int i = 1; i <= n; i++) {
    //     P[i] = i;
    // }
    iota(P.begin() + 1, P.begin() + 1 + n, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // for (auto e: P) {
    //     cout << e << ' ';
    // }

    int ans = 1e9;
    do {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (G[P[i]][P[j]] != H[i][j]) {//排列中的第i和第j个节点是否与H中的第i个和第j个相同
                    res += A[i][j];
                }
            }
        }
        ans = min(ans, res);
    } while (next_permutation(P.begin() + 1, P.begin() + 1 + n));

    cout << ans << '\n';


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
