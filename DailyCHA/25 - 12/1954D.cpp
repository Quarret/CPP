#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 从相邻不同性质出发, 需要子序列最大值和子序列数字之和
// f[i][j] 记录 前 i 个数字组成子序列之和组成 j 的方案数
// 排序保证大值都在后面 
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long ans = 0, MOD = 998244353;
    vector f(n + 1, vector<int>(5001, 0));
    
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 5000; j++) {
            f[i + 1][j] = f[i][j];

            if (a[i] <= j) {
                f[i + 1][j] = (f[i + 1][j] + f[i][j - a[i]]) % MOD;
                // 必须选 a[i]
                ans = (ans + 1LL * f[i][j - a[i]] * max((j + 1) / 2, a[i])) % MOD;
            }
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 正面难做难想吗? 要不试试反面? 正逆序都试试
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 此题有单调性吗? 可以二分答案吗?
4. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
5. 贡献法可以做吗?
6. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/