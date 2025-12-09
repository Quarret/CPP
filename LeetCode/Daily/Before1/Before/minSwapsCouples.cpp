#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minSwapsCouples(vector<int>& row) {
    vector<int> a(row.begin(), row.end());
    sort(a.begin(), a.end());
    
    int n = row.size();
    for (int i = 0; i < n; i++) {
        row[i] = lower_bound(a.begin(), a.end(), row[i]) - a.begin();
    }

    int ans = 0;
    vector<int> vis(n, 0);
    for (int x : row) {
        if (vis[x]) continue;

        int c = 0;
        while (!vis[x]) {
            vis[x] = 1;
            x = row[x];
            c++;
        }

        ans += c - 1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
