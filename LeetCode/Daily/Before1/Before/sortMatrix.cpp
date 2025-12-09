#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> ans;
    for (int k = -(n - 1); k <= (n - 1); k++) {
        int min_j = max(0, k);
        int max_j = min(n - 1, k + n - 1);

        for (int j = min_j; j <= max_j; j++) {
            ans.push_back(grid[j - k][j]);
        }

        if (k <= 0) sort(ans.begin(), ans.end(), greater());
        else sort(ans.begin(), ans.end(), less());

        for (int j = min_j, t = 0; j <= max_j; j++) {
            grid[j - k][j] = ans[t++];
        }
        ans.clear();
    }

    return grid;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
