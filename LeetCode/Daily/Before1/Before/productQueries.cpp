#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    int len = __bit_width(n);
    int MOD = 1e9 + 7;
    vector<int> pre(len + 1);
    
    int idx = 0;
    for (int i = 0; i <= 31; i++) {
        if ((n & (1 << i)) == (1 << i)) {
            pre[idx + 1] = pre[idx] + 1;
            idx++;
        }
    }

    int m = queries.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int l = queries[i][0], r = queries[i][1];
        int cnt = pre[r + 1] - pre[l];

        long long res = 1;
        while (cnt) {
            res = (res * (1 << min(cnt, 16))) % MOD;
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
