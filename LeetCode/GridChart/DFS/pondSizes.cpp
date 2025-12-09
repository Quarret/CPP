/*** 
 * @Author: Quarret
 * @Date: 2025-06-16 21:13:46
 * @LastEditTime: 2025-06-16 21:18:17
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> pondSizes(vector<vector<int>>& land) {
    int m = land.size(), n = land[0].size();

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || i >= m || j < 0 || j >= n || land[i][j] != 0) return 0;
        land[i][j] = 1;

        int res = 1;
        res += dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
        res += dfs(i - 1, j - 1) + dfs(i + 1, j - 1) + dfs(i + 1, j + 1) + dfs(i - 1, j + 1);
        return res;
    };

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 0) {
                ans.push_back(dfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
