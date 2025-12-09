#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> lexSmallestNegatedPerm(int n, long long target) {
    long long maxx = 1LL * (1 + n) * n / 2, minn = -1LL * (1 + n) * n / 2;
    if (target > maxx || target < minn) {
        return {};
    }
    
    long long diff = maxx - target;
    if (diff % 2) {
        return {};
    }

    vector<int> ans, vis(n + 1);
    long long x = n;
    while (diff) {
        x = min(diff / 2, x);
        while (vis[x]) {
            x--;
        }
        ans.push_back(-x);
        diff -= 2 * x;
        vis[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ans.push_back(i);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
