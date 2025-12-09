#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size(), maxx = 0, minn = n;
    vector<int> pre(n + 1, 0), lcnt(n, 0), rcnt(n, 0);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '*');
        if (s[i] == '|') maxx = i;
        rcnt[i] = i - maxx;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '|') minn = i;
        lcnt[i] = minn - i;
    }

    int m = queries.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int l = queries[i][0], r = queries[i][1];
        int num = pre[r + 1] - pre[l];
        if (r - l + 1 - num <= 1) ans.push_back(0);
        else {
            ans.push_back(num - lcnt[l] - rcnt[r]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
