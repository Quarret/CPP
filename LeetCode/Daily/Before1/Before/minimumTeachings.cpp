#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    vector learn(m, vector<bool>(n + 1, false));
    
    for (int i = 0; i < m; i++) {
        for (int x : languages[i]) {
            learn[i][x] = true;
        }
    }

    vector<pair<int, int>> to_doList;
    for (auto &p : friendships) {
        int u = p[0] - 1, v = p[1] - 1;
        bool ok = false;
        for (int x : languages[u]) {
            if (learn[v][x]) {
                ok = true;
                break;
            }
        }

        if (!ok) to_doList.emplace_back(u, v);
    }

    int ans = m;
    for (int k = 1; k <= n; k++) {
        unordered_set<int> st;
        for (auto &[u, v] : to_doList) {
            if (!learn[u][k]) st.insert(u);
            if (!learn[v][k]) st.insert(v);
        }

        ans = min(ans, (int)st.size());
    }

    return ans;
}

int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    vector learn(m, vector<bool>(n + 1, false));
    
    for (int i = 0; i < m; i++) {
        for (int x : languages[i]) {
            learn[i][x] = true;
        }
    }

    int tot = 0;
    vector<int> vis(m);
    vector<int> cnt(n + 1, 0);

    auto add = [&](int u) -> void {
        if (vis[u]) return;

        vis[u] = 1;
        tot++;
        for (int x : languages[u]) {
            cnt[x]++;
        }
    };

    for (auto &f : friendships) {
        int u = f[0] - 1, v = f[1] - 1;
        
        bool ok = false;
        for (int x : languages[u]) {
            if (learn[v][x]) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            add(u);
            add(v);
        }
    }

    return tot - *max_element(cnt.begin(), cnt.end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
