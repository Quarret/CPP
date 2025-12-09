#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
D题在赛时未做出来原因是看掉了一个条件(在数据范围内容中):
l <= real <= r

现在分析怎么做
当x到达某个[l, r]，就要判断它是向左跳还是向右跳
向左跳

x = 3
l real r
1 2 3
1 7 10

首先在[1, 3]区间，若向左跳则到达2，2再次跳跃到达7
即向左跳是无意义的，要么变小要么可以跳向更大的值

现在题目转换为x一路向右跳能够到达的最大值
向右跳是无害的，要么变大，要么跳到下一个可以变大的区间
*/
void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    struct node {
        int l;
        int r;
        int real;
    };
    vector<node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].real;
    }

    sort(a.begin(), a.end(), [&](node x, node y) {
        return x.real < y.real;
    });

    for (int i = 0; i < n; i++) {
        if (k >= a[i].l && k <= a[i].real) {
            k = a[i].real;
        }
    }

    cout << k << '\n';
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
