#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> meet = {{3,1,3},{1,2,2},{0,3,3}};
//write lambda waste too many memory
vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    int idx = 0;
    unordered_set<int> know = {0, firstPerson};

    sort(meetings.begin(), meetings.end(), [&](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    });

    auto f = [&](int t) -> void {
        unordered_map<int, vector<int>> g;

        vector<int> vis(n);
        auto dfs = [&](this auto&& dfs, int u) -> void {
            know.insert(u);

            for (int v : g[u]) {
                if (!know.count(v)) dfs(v);
            }    
        };

        while (idx < meetings.size() && meetings[idx][2] == t) {
            int u = meetings[idx][0], v = meetings[idx][1];
            g[u].push_back(v);
            g[v].push_back(u);
            idx++;
        }

        for (auto &[u, vs] : g) {
            if (know.count(u)) dfs(u);
        }
    };

    for (int t = 0; t <= meetings.back()[2]; t++) f(t);

    vector<int> ans;
    for (int u : know) ans.push_back(u);

    return ans;
}


vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    unordered_set<int> know = {0, firstPerson};//use set to create the vis ans know above

    sort(meetings.begin(), meetings.end(), [&](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    });

    int m = meetings.size();
    for (int i = 0; i < m;) {
        unordered_map<int, vector<int>> g;
        int time = meetings[i][2];
        for (; i < m && meetings[i][2] == time; i++) {
            int u = meetings[i][0], v = meetings[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }


        auto dfs = [&](this auto&& dfs, int u) -> void {
            know.insert(u);

            for (int v : g[u]) {
                if (!know.contains(v)) dfs(v);
            }
        };

        for (auto &[u, vs] : g) {
            if (know.contains(u)) dfs(u);
        }
    }

    vector<int> ans;
    for (int u : know) ans.push_back(u);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    findAllPeople(4, meet, 3);

    return 0;
}
