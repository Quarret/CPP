#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int numTilePossibilities(string tiles) {
    int ans = 0, n = tiles.size();
    unordered_set<string> st;
    vector<int> vis(n);
    string path;
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            if (path.size() && !st.contains(path)) {
                ans++;
                st.insert(path);
            }

            return;
        }

        dfs(i + 1);

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            vis[j] = 1;
            path.push_back(tiles[j]);
            dfs(i + 1);
            path.pop_back();
            vis[j] = 0;
        }
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
