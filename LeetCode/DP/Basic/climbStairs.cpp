#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//memo dfs
int climbStairs(int n) {
    vector<int> memo(n + 1, -1);
    
    auto dfs = [&](this auto&& dfs, int i) -> int {
        if (i == 0) return 1;
        if (i < 0) return 0;

        int &res = memo[i];
        if (res != -1) return res;
        res = dfs(i - 1) + dfs(i - 2);

        return res;
    };

    return dfs(n);
}

//dp
int climbStairs(int n) {
    vector<int> f(n + 1);
    f[0] = f[1] = 1;//horizon

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
