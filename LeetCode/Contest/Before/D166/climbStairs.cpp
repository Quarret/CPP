#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int climbStairs(int n, vector<int>& costs) {
    vector<int> memo(n + 1, -1);

    auto dfs = [&](this auto&& dfs, int i) -> int {
        if (i < 0) return 1e9;
        if (i == 0) return 0;

        int &res = memo[i];
        if (res != -1) return res;
        res = min({1 + dfs(i - 1), 4 + dfs(i - 2), 9 + dfs(i - 3)}) + costs[i - 1];

        return res;
    };

    return dfs(n);
}


int climbStairs(int n, vector<int>& costs) {
    vector<int> f(n + 4, 1e9);
    
    f[3] = 0;
    for (int i = 1; i <= n; i++) {
        f[i + 3] = min({1 + f[i + 2], 4 + f[i + 1], 9 + f[i]}) + costs[i - 1];
    }

    return f[n + 3];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
