#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    int n = watchedVideos.size();
    unordered_map<int, vector<int>> g;
    for (int u = 0; u < n; u++) {
        for (int v : friends[u]) {
            g[u].push_back(v);
        } 
    }
    
    vector<int> dis(n, 1e9);
    queue<int> q;
    q.push(id);
    dis[id] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    unordered_map<string, int> mp;
    for (int u = 0; u < n; u++) {
        if (dis[u] == level) {
            for (string x : watchedVideos[u]) {
                mp[x]++;
            }
        }
    }
    
    vector<string> ans;
    for (auto [s, cnt] : mp) ans.push_back(s);
    sort(ans.begin(), ans.end(), [&](string &a, string &b) {
        if (mp[a] == mp[b]) return a < b;
        return mp[a] > mp[b];
    });


    cout << ("alb" > "aaaa") << '\n';

    return ans; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
