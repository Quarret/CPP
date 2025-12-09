#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> ans(2, 0);
    int val = 0, val1 = 0;
    int cnt[2505]{};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[grid[i][j]]++;
            if (cnt[grid[i][j]] == 2) ans[0] = grid[i][j];
            val ^= grid[i][j];
            val1 ^= i * n + j + 1;
        }
    }

    ans[1] = val1 ^ (val ^ ans[0]);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
