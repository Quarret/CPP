#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 全排列每一多余的石头应该去往 0 的位置, fron 一一对应 to
int minimumMoves(vector<vector<int>>& grid) {
    vector<pair<int, int>> from, to;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j]) {
                for (int k = 1; k < grid[i][j]; k++) {
                    from.emplace_back(i, j);
                }
            } else {
                to.emplace_back(i, j);
            }
        }
    }

    int ans = INT_MAX;
    do {
        int tot = 0;
        int m = to.size();
        for (int i = 0; i < m; i++) {
            tot += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
        }

        ans = min(ans, tot);
    } while (next_permutation(from.begin(), from.end()));

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
