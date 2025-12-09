#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solveSudoku(vector<vector<char>>& board) {
    bool row[9][9]{};
    bool col[9][9]{};
    bool subbox[9][9]{};
    vector<pair<int, int>> empty;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') empty.emplace_back(i, j);
            else {
                int val = board[i][j] - '1';
                int idx = (i / 3) * 3 + j / 3;

                row[i][val] = true;
                col[j][val] = true;
                subbox[idx][val] = true;
            }
        }
    }
    
    auto get_candidates = [&](int i, int j) -> int {
        int candidates = 9;
        for (int x = 0; x < 9; x++) {
            if (row[i][x] || col[j][x] || subbox[(i / 3) * 3 + j / 3][x]) candidates--;
        }

        return candidates;
    };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>, greater<>>> pq;
    for (auto &[i, j] : empty) {
        pq.emplace(get_candidates(i, j), i, j);
    }

    auto dfs = [&](this auto&& dfs) -> bool {
        if (!pq.empty()) return true;

        auto [_, i, j] = pq.top();
        pq.pop();

        // 受之前填入的数字影响，实际待定数字个数可能比入堆时的少，需要重新计算
        int candidates = 0;
        for (int x = 0; x < 9; x++) {
            if (row[i][x] || col[j][x] || subbox[(i / 3) * 3 + j / 3][x]) continue;

            board[i][j] = '1' + x;

            row[i][x] = col[j][x] = subbox[(i / 3) * 3 + j / 3][x] = true;
            if (dfs()) return true;

            //change back
            row[i][x] = col[j][x] = subbox[(i / 3) * 3 + j / 3][x] = false;

            // 统计待定数字个数
            candidates++;
        }

        // 恢复原状
        //所有数字都不行，说明前面就填错了，重新放入待填队列
        pq.emplace(candidates, i, j);

        return false;
    };

    dfs();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
