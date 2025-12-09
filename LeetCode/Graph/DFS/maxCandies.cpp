#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int n = status.size();
    vector<int> in_deg(n);
    for (int i = 0; i < n; i++) {
        for (int j : containedBoxes[i]) {
            in_deg[j]++;
        }
    }

    auto cmp = [&](int a, int b) -> bool {
        return status[a] < status[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    int ans = 0;
    for (int u : initialBoxes) pq.push(u);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        if (!status[u]) break;
        ans += candies[u];

        for (int v : keys[u]) status[v] = 1;
        for (int v : containedBoxes[u]) {
            in_deg[v]--;
            if (!in_deg[v]) {
                pq.push(v);
            }
        }
        if (!pq.empty()) {
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp);
        }
    }

    return ans;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int n = status.size();
    vector<int> in_deg(n), vis(n);
    for (int i = 0; i < n; i++) {
        for (int j : containedBoxes[i]) {
            in_deg[j]++;
            vis[j] = 1;
        }
    }
    
    for (int u : initialBoxes) vis[u] = 1;
    queue<int> q;
    int ans = 0;
    for (int u = 0; u < n; u++) {
        if (!in_deg[u] && status[u] && vis[u]) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += candies[u];
        
        for (int v : keys[u]) {
            if (!in_deg[v] && vis[u]) {
                in_deg[v]--;
                q.push(v);
            }
            status[v] = 1;
        }

        for (int v : containedBoxes[u]) {
            in_deg[v]--;
            if (!in_deg[v] && status[v] && vis[u]) {
                in_deg[v]--;
                q.push(v);
            }
        }
    }

    return ans;
}


int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int n = status.size();
    vector<int> has_box(n), vis(n);

    queue<int> q;
    for (int u : initialBoxes) {
        has_box[u] = 1;
        if (has_box[u] && status[u] && !vis[u]) {
            vis[u] = 1;
            q.push(u);
        }
    }
    
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += candies[u];
        

        for (int v : containedBoxes[u]) {
            has_box[v] = 1;
            if (has_box[v] && status[v] && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }

        for (int v : keys[u]) {
            status[v] = 1;
            if (has_box[v] && status[v] && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
