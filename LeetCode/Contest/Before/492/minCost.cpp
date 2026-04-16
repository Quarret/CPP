#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minCost(string s, int encCost, int flatCost) {
    int n = s.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '1');
    }

    // [l, r) 前闭后开区间
    auto dfs = [&](this auto&& dfs, int l, int r) -> long long {
        // 不拆分
        int x = pre[r] - pre[l];
        long long res = x ? 1LL * (r - l) * x * encCost : flatCost;

        if ((r - l) % 2 == 0) {
            int mid = (l + r) / 2;
            res = min(res, dfs(l, mid) + dfs(mid, r));
        }

        return res;
    };

    return dfs(0, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}