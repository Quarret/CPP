#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minIncrements(int n, vector<int>& cost) {    
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int root) -> int {
        if (root >= n) {
            return 0;
        }

        int left = dfs(root * 2 + 1);
        int right = dfs(root * 2 + 2);

        ans += abs(left - right);
        return max(left, right) + cost[root];
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
