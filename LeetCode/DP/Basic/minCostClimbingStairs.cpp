#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> memo(n + 1, -1);

    auto dfs = [&](this auto&& dfs, int i) -> int {
        if (i < 2) return 0;

        int &res = memo[i];
        if (res != -1) return res;
        res = min(dfs(i - 2) + cost[i - 2], dfs(i - 1) + cost[i - 1]);

        return res;
    };

    return dfs(n);
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> f(n + 1);
    f[0] = f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
