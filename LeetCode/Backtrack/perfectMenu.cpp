#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
    int n = cookbooks.size(), ans = -1, m = materials.size();
    auto dfs = [&](this auto&& dfs, int i, vector<int> path, int x, int y) -> void {
        for (int j = 0; j < m; j++) {
            if (path[j] < 0) return;
        }

        if (i == n) {
            if (y >= limit) {
                ans = max(ans, x);
            }
            return;
        }

        dfs(i + 1, path, x, y);

        for (int j = 0; j < m; j++) {
            path[j] -= cookbooks[i][j];
        }
        dfs(i + 1, path, x + attribute[i][0], y + attribute[i][1]);
    };

    dfs(0, materials, 0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
