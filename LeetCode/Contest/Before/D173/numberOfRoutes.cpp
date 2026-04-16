#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfRoutes(vector<string>& grid, int d) {
    int n = grid.size(), m = grid[0].size();
    const int MOD = 1e9 + 7;

    int cnt = 0;
    if (n == 1) {
        int ans = 0;
    }

    if (m == 1) {
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == '#') return 0;
        }
        return 1;
    }

    vector memo(n, vector(m, array<int, 2>{-1, -1}));
    auto dfs = [&](this auto&& dfs, int i, int j, int c) -> int {
        if (i == 0) {
            return 1;
        }

        int &res = memo[i][j][c];
        if (res != -1) {
            return res;
        }

        res = 0;
        for (int x = i; x >= max(0, i - d); x--) {
            if (x == i && c == 1) continue;
            for (int y = max(0, j - d); y <= min(m - 1, j + d); y++) {
                if (grid[i][j] == '#') continue;
                if ((x - i) * (x - i) + (y - j) * (y - j) > d * d) continue;
                res = (res + dfs(x, y, (x == i ? 1 : 0))) % MOD;
            }
        };

        memo[i][j][c] = res;
        return res;
    };

    int ans = 0;
    for (int j = 0; j < m; j++) {
        if (grid[n - 1][j] == '#') continue;
        ans = (ans + dfs(n - 1, j, 0)) % MOD;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

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