#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long numberOfWays(string s) {
    int n = s.size();
    
    vector memo(n, vector(4, array<long long, 2>{-1, -1}));
    // 前 i 个选了 c 个字母最后一个字母为 last 的方案数
    // 注意: 记忆化搜索中所有状态量要求的都是当前 nums[i]
    auto dfs = [&](this auto&& dfs, int i, int c, int last) -> long long {
        if (c == 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }

        long long &res = memo[i][c][last];
        if (res != -1) {
            return res;
        }

        res = dfs(i - 1, c, last);
        if (s[i] - '0' == last) {
            res += dfs(i - 1, c - 1, last ^ 1);
        }
        return res;
    };

    return dfs(n - 1, 3, 0) + dfs(n - 1, 3, 1);
}

long long numberOfWays(string s) {
    int n = s.size();
    
    vector f(n + 1, vector(4, array<long long, 2>{0, 0}));
    for (int i = 0; i <= n; i++) {
        f[i][0][0] = 1;
        f[i][0][1] = 1;
    }

    for (int i = 0; i < n; i++) {
        int now = s[i] - '0';
        for (int c = 0; c <= 3; c++) {
            for (int last = 0; last < 2; last++) {
                f[i + 1][c][last] = f[i][c][last];
                if (now == last && c != 0) {
                    f[i + 1][c][last] += f[i][c - 1][last ^ 1];
                }
            }
        }
    }

    return f[n][3][0] + f[n][3][1];
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
4. 正面难做难想吗? 要不试试反面? 正逆序都试试
5. 此题有单调性吗? 可以二分答案吗?
6. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
7. 贡献法可以做吗?
8. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/