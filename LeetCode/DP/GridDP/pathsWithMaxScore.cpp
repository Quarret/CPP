#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> pathsWithMaxScore(vector<string>& board) {
    int n = board.size(), MOD = 1e9 + 7;
    vector f0(n + 2, vector<int>(n + 2, 0)), f1(n + 2, vector<int>(n + 2, 0));
    
    f1[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j] == 'X') continue;
            int val = board[i][j] == 'S' || board[i][j] == 'E' ? 0 : board[i][j] - '0';
            f0[i][j] = (max({f0[i][j + 1], f0[i + 1][j], f0[i + 1][j + 1]}) + val) % MOD;
            if (f0[i][j] == f0[i][j + 1] + val) f1[i][j] = (f1[i][j] + f1[i][j + 1]) % MOD;
            if (f0[i][j] == f0[i + 1][j] + val) f1[i][j] = (f1[i][j] + f1[i + 1][j]) % MOD;
            if (f0[i][j] == f0[i + 1][j + 1] + val) f1[i][j] = (f1[i][j] + f1[i + 1][j + 1]) % MOD;
        }
    }

    if (f1[0][0]) return {f0[0][0], f1[0][0]};
    return {0, 0};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
