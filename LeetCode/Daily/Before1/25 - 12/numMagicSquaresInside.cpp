#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int c1 = 0, c2 = 0, c3 = 0;
            int r1 = 0, r2 = 0, r3 = 0;
            int diag1 = 0, diag2 = 0;

            unordered_set<int> st;

            int mx = 0;
            for (int r = i; r <= i + 2; r++) {
                for (int c = j; c <= j + 2; c++) {
                    if (r - i == 0) r1 += grid[r][c];
                    else if (r - i == 1) r2 += grid[r][c];
                    else r3 += grid[r][c];

                    if (c - j == 0) c1 += grid[r][c];
                    else if (c - j == 1) c2 += grid[r][c];
                    else c3 += grid[r][c];

                    if (r - i == c - j) diag1 += grid[r][c];
                    if (r + c == i + j + 2) diag2 += grid[r][c];

                    st.insert(grid[r][c]);
                    mx = max(mx, grid[r][c]);
                }
            }

            // cout << diag1 << ' ' << diag2 << '\n';
            if (r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == diag1 && diag1 == diag2 
                && st.size() == 9 && mx == 9) {
                ans++;
            }
        }
    }

    return ans;
}

// 数学
// 幻方最中心的数字一定是 5
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            if (grid[i + 1][j + 1] != 5) continue;

            int sum_r[3]{};
            int sum_c[3]{};
            int mask = 0;

            // 直接枚举相对量
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    int x = grid[i + r][j + c];

                    mask |= 1 << x;
                    sum_r[r] += x;
                    sum_c[c] += x;
                }
            }

            if (mask == (1 << 10) - 2 && 
                sum_c[0] == 15 && sum_c[1] == 15 && 
                sum_r[0] == 15 && sum_r[1] == 15) {
                    ans++;
                }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 这道题与位置无关吗? 可以先排序吗?
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 看到一些熟悉的性质? 试试从性质中的变量出发
4. 试着从循环不变量着手思考
5. 正面难做难想吗? 要不试试反面? 正逆序都试试
6. 此题有单调性吗? 可以二分答案吗?
7. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
8. 贡献法可以做吗?
9. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/