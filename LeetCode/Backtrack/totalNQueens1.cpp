#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int totalNQueens(int n) {
    int ans = 0;
    vector<int> col(n), diag1(2 * n - 1), diag2(2 * n - 1);

    auto dfs = [&](this auto&& dfs, int r) -> void {
        if (r == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !diag1[r + c] && !diag2[r - c + n - 1]) {
                col[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;
                dfs(r + 1);
                col[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
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
