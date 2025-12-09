#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumRequests(int n, vector<vector<int>>& requests) {
    int m = requests.size();
    vector<int> out(n), in(n);
    
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int i, int cnt) -> void {
        if (i == m) {
            int ok = 1;
            for (int j = 0; j < n; j++) {
                if (out[j] != in[j]) {
                    ok = 0;
                }
            }
            if (ok) ans = max(ans, cnt);
            return;
        }

        dfs(i + 1, cnt);

        auto e = requests[i];
        int from = e[0], to = e[1];

        out[from]++;
        in[to]++;

        dfs(i + 1, cnt + 1);

        out[from]--;
        in[to]--;
    };

    dfs(0, 0);
    return ans;
}

int maximumRequests(int n, vector<vector<int>>& requests) {
    int m = requests.size();
    
    int ans = 0;
    for (int k = 0; k < (1 << m); k++) {
        vector<int> cnt(n);
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (k >> i & 1) {
                cnt[requests[i][0]]++;
                cnt[requests[i][1]]--;
                res++;
            }
        }

        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (cnt[i]) {
                ok = 0;
            }
        }

        if (ok) ans = max(ans, res);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
