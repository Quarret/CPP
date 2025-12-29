#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maxScore(vector<int>& nums, int x) {
    int n = nums.size();
    
    vector memo(n, array<long long, 2>{-1, -1});
    // memo[i][j] 代表从 i 到 n - 1, 第一个数的奇偶性为 j 的最大子序列和
    auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
        if (i == n) {
            return 0;
        }

        long long &res = memo[i][j];
        if (res != -1) {
            return res;
        }

        if (nums[i] % 2 != j) {
            return res = dfs(i + 1, j);
        }
        return res = max(dfs(i + 1, j), dfs(i + 1, j ^ 1) - x) + nums[i];
    };

    return dfs(0, nums[0] % 2);
}

long long maxScore(vector<int>& nums, int x) {
    int n = nums.size();
    vector f(n + 1, array<long long, 2>{0, 0});
    
    for (int i = n - 1; i >= 0; i--) {
        int u = nums[i], r = u % 2;
        // r != j
        f[i][r ^ 1] = f[i + 1][r ^ 1];
        f[i][r] = max(f[i + 1][r], f[i + 1][r ^ 1] - x) + u;
    }

    return f[0][nums[0] % 2];
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