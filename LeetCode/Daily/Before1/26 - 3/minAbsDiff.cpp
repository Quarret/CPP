#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector ans(m - k + 1, vector<int>(n - k + 1, 0));
    
    for (int i = 0; i < max(m - k + 1, 0); i++) {
        for (int j = 0; j < max(n - k + 1, 0); j++) {
            set<int> st;
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    st.insert(grid[x][y]);
                }
            }

            int res = INT_MAX, pre = *st.begin();
            for (int x : st) {
                if (pre != x) res = min(res, abs(pre - x));
                pre = x;
            }

            ans[i][j] = res == INT_MAX ? 0 : res;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}