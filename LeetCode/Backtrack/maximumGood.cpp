#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumGood(vector<vector<int>>& statements) {
    int n = statements.size();
    
    int ans = 0;
    for (int k = 0; k < (1 << n); k++) {
        int ok = 1;
        int path = k;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (path & (1 << i)) {
                q.push(i);
            }
        }

        vector<int> is_bad(n);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (statements[u][v] == 0) {
                    if ((path & (1 << v)) != 0) {
                        ok = 0;
                    }
                    is_bad[v] = 1;
                } else if (statements[u][v] == 1) {
                    if ((path & (1 << v)) == 0) {
                        q.push(v);
                    }
                    if (is_bad[v]) {
                        ok = 0;
                    }
                    path |= 1 << v;
                }
            }

            if (!ok) break;
        }

        if (ok) {
            ans = max(ans, __builtin_popcount(path));
        }
    }

    return ans;
}


// 枚举就放空大脑, 只检查枚举情况是否合理
int maximumGood(vector<vector<int>>& statements) {
    int n = statements.size(), ans = 0;
    for (int k = 0; k < (1 << n); k++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((k >> i & 1) == 0) continue;
            cnt++;
            for (int j = 0; j < n; j++) {
                if (statements[i][j] < 2 && statements[i][j] != (k >> j & 1)) {
                    goto next;
                }
            }

        }
        ans = max(ans, cnt);
        next: ;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
