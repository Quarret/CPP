#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    ll ans = H * W;

    vector< set<int> > r(H + 1), c(W + 1);

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            r[i].insert(j);
            c[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (*r[R].lower_bound(C) == C) {
            r[R].erase(C);
            c[C].erase(R);
            ans--;
        } else {
            auto it = r[R].lower_bound(C);

            if (it != r[R].begin()) {
                int b = *prev(it);
                r[R].erase(b);
                c[b].erase(R);
                ans--;
            }

            if (it != r[R].end()) {
                int b = *it;
                r[R].erase(b);
                c[b].erase(R);
                ans--;
            }

            it = c[C].lower_bound(R);
            if (it != c[C].begin()) {
                int b = *prev(it);
                ans--;
                c[C].erase(b);
                r[b].erase(C);
            }

            if (it != c[C].end()) {
                int b = *it;
                ans--;
                c[C].erase(b);
                r[b].erase(C);
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
