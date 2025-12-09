#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    unordered_map<int, vector<pair<int, int>>> g;
    int n = routes.size(), maxx = -1;
    for (int t = 0; t < n; t++) {
        auto r = routes[t];
        for (int i = 0; i < r.size(); i++) {
            int u = r[i], v = r[(i + 1) % r.size()];
            maxx = max(maxx, u);
            g[u].emplace_back(v, t);
        }
    }

    vector<int> cnt(maxx + 1, 1e9);
    vector<vector<int>> vis(maxx + 1, vector<int>(n + 2, 0));
    // deque<tuple<int, int, int>> q;
    // q.emplace_front(source, n + 1, 0);
    auto cmp = [](tuple<int, int, int> t1, tuple<int, int, int> t2) {
        auto [u1, t1, val1] = t1;
        auto [u2, t2, val2] = t2;
        return val1 > val2;
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq;
    pq.push({source, n + 1, 0});
    cnt[source] = 0;

    while (!pq.empty()) {
        // auto [u, idx, cur] = q.front();
        // q.pop_front();
        auto [u, idx, cur] = pq.top();
        
        for (auto [v, t] : g[u]) {
            if (!vis[v][idx] && (idx != t) + cur <= cnt[v]) {
                vis[v][idx] = 1;
                cnt[v] = (idx != t) + cur;
                pq.push({v, t, cnt[v]});
                // if (idx != t) q.emplace_back(v, t, cnt[v]);
                // else q.emplace_front(v, t, cnt[v]);  
            } else if (idx != t && 1 + cur < cnt[v]) {
                cnt[v] = 1 + cur;
                pq.push({v, t, cnt[v]});
                // q.emplace_back(v, t, cnt[v]);
            } else if (idx == t && cur < cnt[v]) {
                cnt[v] = cur;
                pq.push({v, t, cnt[v]});
                // q.emplace_front(v, t, cnt[v]);
            }
        }
    }

    if (target > maxx) return -1;
    return cnt[target] == 1e9 ? -1 : cnt[target];
}


/*
原做法图建的有问题
题目问的是，最小公交车数量，但原图节点是站号，导致后续判断公交数需要大量状态量来判断
建好图必后续的代码重要多!!
*/
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < routes.size(); i++) {
        for (int u : routes[i]) {
            g[u].push_back(i);
        }
    }
    
    if (!g.contains(source) || !g.contains(target)) return source == target ? 0 : -1;

    unordered_map<int, int> dis;
    queue<int> q;
    q.push(source);
    dis[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int dis_u = dis[u];
        for (int i : g[u]) {//all bus passed u
            for (int v : routes[i]) {
                if (!dis.contains(v)) {//w = 1 bfs is the shortest 
                    dis[v] = dis_u + 1;
                    q.push(v);
                }
            }
            routes[i].clear();//avoid the circle
        }
    }

    return dis.contains(target) ? dis[target] : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
