#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxUniqueSplit(string s) {
    int n = s.size();
    unordered_map<string, int> path;

    int ans = 0;
    auto dfs = [&](this auto&& dfs, int i, int start, int cnt) -> void {
        if (i == n) {
            ans = max(ans, cnt);
            return;
        }

        if (i < n - 1) {
            dfs(i + 1, start, cnt);
        }

        string t = s.substr(start, i - start + 1);
        if (!path[t]) {
            path[t] = 1;
            dfs(i + 1, i + 1, cnt + 1);
            path[t] = 0;
        }
    };

    dfs(0, 0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
