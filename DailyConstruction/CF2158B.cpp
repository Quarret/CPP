#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> cnt;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int even = 0, odd = 0;
    int mod4_odd = 0;
    int mod4_2 = 0;
    int mod4_0 = 0;
    for (auto [_, c] : cnt) {
        if (c % 2) mod4_odd++;
        else if (c % 4 == 0) mod4_0++;
        else mod4_2++;
    }

    int ans = mod4_odd + 2 * mod4_2 + 2 * mod4_0;
    if (mod4_odd == 0 && mod4_0 % 2) ans -= 2;
    cout << ans << '\n';
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