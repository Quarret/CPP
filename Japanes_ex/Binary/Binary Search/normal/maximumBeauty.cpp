#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> items = {{10,1000}};
vector<int> que = {5};
int check(vector<vector<int>>& items, int k) {
    int l = 0, r = items.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (items[mid][0] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int n = items.size(), m = queries.size(), num = 0;
    vector<int> ans(m, 0);

    sort(items.begin(), items.end(), [&](vector<int> x, vector<int> y) {
        return x[0] < y[0];
    });

    int maxx = items[0][1];
    for (int i = 1; i < n; i++) {
        maxx = max(maxx, items[i][1]);
        items[i][1] = maxx;
    }

    for (int i = 0; i < m; i++) {
        num = check(items, queries[i] + 1) - 1;
        if (num < 0) ans[i] = 0;
        else ans[i] = items[num][1];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maximumBeauty(items, que);

    return 0;
}
