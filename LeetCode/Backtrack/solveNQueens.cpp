#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> col(n), diag1(2 * n - 1), diag2(2 * n - 1), path(n);
    vector board(n, string(n, '.'));
    
    auto dfs = [&](this auto&& dfs, int r) -> void {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !diag1[r + c] && !diag2[r - c + n - 1]) {
                board[r][c] = 'Q';
                col[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;
                path[r] = c;
                dfs(r + 1);
                col[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
                board[r][c] = '.';
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
