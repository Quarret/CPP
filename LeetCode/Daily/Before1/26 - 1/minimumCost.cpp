#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    using ll = long long;
    unordered_map<int, vector<pair<int, ll>>> g;
    
    int m = original.size();
    for (int i = 0; i < m; i++) {
        char x = original[i] - 'a', y = changed[i] - 'a', c = cost[i];
        g[x].emplace_back(y, c);
    }

    vector d(26, vector<ll>(26, LLONG_MAX));
    for (int start = 0; start < 26; start++) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.emplace(0, start);
        d[start][start] = 0;

        while (!pq.empty()) {
            auto [s, x] = pq.top();
            pq.pop();

            for (auto [y, c] : g[x]) {
                ll new_s = s + c;
                if (new_s < d[start][y]) {
                    d[start][y] = new_s;
                    pq.emplace(new_s, y);
                }
            }
        }
    }

    ll ans = 0, n = source.size();
    for (int i = 0; i < n; i++) {
        int x = source[i] - 'a', y = target[i] - 'a';
        if (d[x][y] == LLONG_MAX) return -1;
        ans += d[x][y];
    }

    return ans;
}


// floyd 算法
// 路径上的最大节点 k
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    using ll = long long;
    const ll INF = LLONG_MAX / 2;
    vector d(26, vector<ll>(26, INF));
    for (int i = 0; i < 26; i++) {
        d[i][i] = 0;
    }

    for (int i = 0; i < original.size(); i++) {
        int x = original[i] - 'a', y = changed[i] - 'a'; 
        ll c = cost[i];
        d[x][y] = min(d[x][y], c);
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            if (d[i][k] == INF) {
                continue;
            }

            for (int j = 0; j < 26; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < source.size(); i++) {
        int x = source[i] - 'a';
        int y = target[i] - 'a';
        ll wt = d[x][y];
        if (wt == INF) return -1;
        ans += wt;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}