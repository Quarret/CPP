#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int colorTheGrid(int m, int n) {
    using ll = long long;
    const int MOD = 1e9 + 7;

    unordered_map<ll, int> memo;
    auto dfs = [&](this auto&& dfs, ll i, ll j, ll pre_col, ll cur_col) -> int {
        if (j < 0) {
            return 1;
        }

        if (i == m) {
            return dfs(0, j - 1, cur_col, 0);
        }

        long long mask = (i << 30) | (j << 20) | (pre_col << 10) | cur_col;
        if (memo.contains(mask)) {
            return memo[mask];
        }

        int res = 0;
        for (ll color = 1; color <= 3; color++) {
            if (pre_col > 0 && color == (pre_col >> (i * 2) & 3) ||
                i > 0 && color == (cur_col >> ((i - 1) * 2) & 3)) {
                continue;
            }
            res = (res + dfs(i + 1, j, pre_col, cur_col | (color << (i * 2)))) % MOD;
        }

        memo[mask] = res;
        return res;
    };

    return dfs(0, n - 1, 0, 0);
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