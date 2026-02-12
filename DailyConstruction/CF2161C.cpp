#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, X;
    cin >> n >> X;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long i = 0, j = n - 1, s = 0, ans = 0;
    sort(a.begin(), a.end());
    vector<int> res;
    while (i <= j) {
        if ((s + a[j]) / X > s / X) {
            ans += a[j];
            s += a[j];
            res.push_back(a[j]);
            j--;
            continue;
        } else {
            if ((s + a[i]) / X > s / X) {
                ans += a[i];
            }
            res.push_back(a[i]);
            s += a[i];
            i++;
        }
    }

    cout << ans << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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