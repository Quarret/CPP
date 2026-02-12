#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numOfWays(int n) {
    const int MOD =  1e9 + 7;
    unordered_map<int, int> memo;
    auto dfs = [&](this auto&& dfs, int i, int j, int pre_row, int cur_row) -> int {
        if (i < 0) {
            return 1;
        }

        if (j == 3) {
            return dfs(i - 1, 0, cur_row, 0);
        }

        int mask = (i << 14) | (j << 12) | (pre_row << 6) | cur_row;
        if (memo.contains(mask)) {
            return memo[mask];
        }

        int res = 0;
        for (int c = 0; c < 3; c++) { // 枚举 (i, j) 的颜色
            if (pre_row > 0 && c == (pre_row >> (j * 2) & 3) || // 不能与 (i - 1, j) 颜色相同
                j > 0 && c == (cur_row >> ((j - 1) * 2) & 3)) { // 不能与 (i, j - 1) 颜色相同
                continue;
            }
            res = (res + dfs(i, j + 1, pre_row, cur_row | (c << (j * 2)))) % MOD;
        }

        memo[mask] = res;
        return res;
    };
    
    return dfs(n - 1, 0, 0, 0);
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