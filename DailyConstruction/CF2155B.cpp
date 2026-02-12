#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n * n == k + 1) {
        cout << "No\n";
        return;
    }
    k = n * n - k;

    vector ans(n, vector<char>(n, 'U'));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i == n - 1) {
                ans[i][j] = 'L';
            } else {
                ans[i][j] = 'D';
            }
            k--;

            if (k <= 0) {
                cout << "Yes\n";
                ans[n - 1][0] = 'R';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout <<  ans[i][j];
                    }
                    cout << '\n';
                }
                return;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

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