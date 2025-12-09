#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findMinimumTime(vector<int>& strength, int k) {
    int n = strength.size();
    int ans = 1e9;
    vector<int> path, vis(n);

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            int X = 1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (path[i] + X - 1) / X;
                X += k;
            }

            ans = min(ans, sum);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                vis[j] = 1;
                path.push_back(strength[j]);
                dfs(i + 1);
                path.pop_back();
                vis[j] = 0;
            }
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
