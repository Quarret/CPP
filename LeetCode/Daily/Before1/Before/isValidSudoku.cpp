#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector row(9, vector<int>(10, 0)), col(9, vector<int>(10, 0));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int val = board[i][j] - '0';
            row[j][val]++;
            col[i][val]++;
            if (row[i][val] > 1 || col[j][val] > 1) return false;
        }
    }
    
    for (int k = 0; k < 9; k++) {
        vector<int> cnt(10, 0);
        int r = (k / 3) * 3, c = (k % 3) * 3;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                cnt[val]++;
                if (cnt[val] > 1) return false;
            }
        }
    }

    return true;
}


bool isValidSudoku(vector<vector<char>>& board) {
    bool box[9][10], row[9][10], col[9][10];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int val = board[i][j] - '0';

            int idx_box = (i / 3) * 3 + j / 3;

            if (row[i][val] || col[j][val] || box[idx_box][val]) return false;
            row[i][val] = true;
            col[j][val] = true;
            box[idx_box][val] = true;
        }
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
