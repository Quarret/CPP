#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    int len = __bit_width(n);
    vector<int> pre(len + 1, 0);
    
    for (int i = 0; i < len; i++) {
        if ((n & (1 << i)) == (1 << i)) {
            pre[i + 1] = pre[i] + i;
        } else pre[i + 1] = pre[i];
    }

    int m = queries.size(), MOD = 1e9 + 7;
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int l = queries[i][0], r = queries[i][1];
        int cnt = pre[r + 1] - pre[l];

        int res = 1;
        while (cnt) {
            res = (res * (1 << min(16, cnt))) % MOD;
            if (cnt >= 16) cnt -= 16;
            else cnt = 0;
        }
        ans[i] = res;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
