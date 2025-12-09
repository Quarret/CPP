#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> constructDistancedSequence(int n) {
    int m = 1 + (n - 1) * 2;
    string path(m, ' '), ans(m, '0');
    vector<int> prev(n + 1, -1), cnt(n + 1);

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == m) {
            ans = max(ans, path);
            return;
        }

        if (cnt[1] == 0) {
            cnt[1]++;
            path[i] = '1';
            dfs(i + 1);
            cnt[1]--;
        }

        for (int j = 2; j <= n; j++) {
            if (!cnt[j]) {
                cnt[j]++;
                prev[j] = i;
                path[i] = j + '0';
                dfs(i + 1);
                prev[j] = -1;
                cnt[j]--;
            } else if (cnt[j] == 1) {
                cnt[j]++;
                if (i + j >= m) continue;
                if (i - prev[j] == j) {
                    path[i] = j + '0';
                    dfs(i + 1);
                }
                cnt[j]--;
            }
        }
    };

    dfs(0);
    vector<int> res;
    for (char c : ans) {
        res.push_back(c - '0');
    }
    return res;
}

// 试填法 + 贪心, 填好就返回, 从大到小遍历保证最大
vector<int> constructDistancedSequence(int n) {
    int m = 2 * (n - 1) + 1;
    vector<int> res(m, 0), vis(n + 1);
    
    auto dfs = [&](this auto&& dfs, int i) -> bool {
        if (i == m) {
            return true;
        }

        if (res[i] != 0) return dfs(i + 1);

        for (int j = n; j >= 1; j--) {
            if (vis[j]) continue;
            if (j == 1) {
                vis[j] = 1;
                res[i] = 1;
                if (dfs(i + 1)) {
                    return true;
                }
                vis[j] = 0;
                res[i] = 0;
            } else {
                if (i + j >= m) continue;
                if (res[i + j] != 0) continue;
                res[i] = res[i + j] = j;
                vis[j] = 1;
                if (dfs(i + 1)) return true;
                res[i] = res[i + j] = 0;
                vis[j] = 0;
            }
        }

        return false;
    };

    dfs(0);

    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
