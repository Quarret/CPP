#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int integerReplacement(int n) {
    unordered_map<int, int> memo;
    
    auto dfs = [&](this auto&& dfs, int x) -> int {
        if (x == 1) {
            return 0;
        }

        if (memo.contains(x)) return memo[x];
        int res = 0;
        if (x % 2) {
            res = min(dfs(x + 1), dfs(x - 1)) + 1;
        } else {
            res = dfs(x / 2) + 1;
        }

        memo[x] = res;
        return res;
    };

    return dfs(n);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
