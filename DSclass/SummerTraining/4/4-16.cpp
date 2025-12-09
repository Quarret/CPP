#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
// int sum[10200]; 
// int vis[10200]; 
// int num[110]; 
void solve() {
    int m = (n * (n - 1)) / 2;

    vector<int> sum(10200, 0), vis(10200, 0), num(110, 0);
    for (int i = 1; i <= m; i++) {
        cin >> sum[i];
    }
    
    for (int i = 3; i <= m; i++) {
        num[1] = (sum[1] + sum[2] - sum[i]) / 2;
        num[2] = sum[1] - num[1];
        num[3] = sum[2] - num[1];

        if ((sum[1] + sum[2] - sum[i]) % 2 || (sum[1] + sum[2] - sum[i]) <= 0) {
            continue;
        }

        //memset(vis, 0, sizeof(vis));
        // for (int j = 0; j <= m; j++) {
        //     vis[j] = 0;
        // }
        vis.assign(vis.size(), 0);

        vis[1] = vis[2] = vis[i] = 1;

        int know = 3;
        int flag = 1;
        while (know != n) {
            int minn = 0;

            for (int j = 1; j <= m; j++) {
                if (vis[j] == 0) {
                    minn = sum[j];
                    vis[j] = 1;
                    break;
                }
            }

            num[know + 1] = minn - num[1];
            know++;


            for (int p = 2; p <= know - 1; p++) {
                int temp = num[p] + num[know];

                flag = 0;

                for (int h = 1; h <= m; h++) {
                    if (!vis[h] && sum[h] == temp) {
                        flag = 1;
                        vis[h] = 1;
                        break;
                    }
                    
                }
                if (!flag) break;
            }
            if (!flag) break;
        }

        if (know != n) continue;

        for (int p = 1; p <= n; p++) {
            cout << num[p] << ' ';
        }
        cout << '\n';
        break; 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> n;
        if (!n) return 0;

        solve();
    }
}
