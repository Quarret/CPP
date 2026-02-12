#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    vector pre(n + 1, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i + 1][j] = (mat[i][j] == '1') + pre[i][j];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = 0;
            for (int r = 0, l = 0; r < m; r++) {
                s += pre[j + 1][r] - pre[i][r];

                while (s >= k) {
                    // cout << s << '\n';
                    // cout << i << ' ' << j << ' ' << l << ' ' << r << '\n';
                    ans = min(ans, (j - i + 1) * (r - l + 1));
                    s -= pre[j + 1][l] - pre[i][l];
                    l++;
                }
            }
        }
    }

    cout << (ans == INT_MAX ? 0 : ans) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

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