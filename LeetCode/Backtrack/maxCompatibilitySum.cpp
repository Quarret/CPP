#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    int n = students.size(), m = students[0].size(), ans = -1;
    vector<int> vis(n), path(n);

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            int tot = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    tot += students[path[i]][j] == mentors[i][j];
                }
            }
            ans = max(ans, tot);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            vis[j] = 1;
            path[i] = j;
            dfs(i + 1);
            vis[j] = 0;
        }
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
