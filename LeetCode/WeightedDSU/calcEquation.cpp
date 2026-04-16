#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class UnionFind {
public:
    vector<int> fa;
    vector<double> mul; // mul[x]: x / 代表元

    UnionFind(int n) : fa(n), mul(n, 1) {
        ranges::iota(fa, 0);
    }

    int find(int x) {
        if (fa[x] != x) {
            int root = find(fa[x]);
            mul[x] *= mul[fa[x]];
            fa[x] = root;
        }
        return fa[x];
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int from, int to, double value) {
        int x = find(from), y = find(to);
        if (x == y) {
            return;
        }

        mul[x] = value * mul[to] / mul[from];
        fa[x] = y;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> variable_to_id;
        for (auto &equation : equations) {
            for (auto &s : equation) {
                if (!variable_to_id.contains(s)) {
                    variable_to_id[s] = variable_to_id.size();
                }
            }
        }

        UnionFind dsu(variable_to_id.size());
        for (int i = 0; i < equations.size(); i++) {
            dsu.merge(variable_to_id[equations[i][0]], variable_to_id[equations[i][1]], values[i]);
        }

        vector<double> ans;
        for (auto &query : queries) {
            auto it_c = variable_to_id.find(query[0]);
            if (it_c == variable_to_id.end()) {
                ans.push_back(-1);
                continue;
            }

            auto it_d = variable_to_id.find(query[1]);
            if (it_d == variable_to_id.end() || !dsu.is_same(it_c->second, it_d->second)) {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(dsu.mul[it_c->second] / dsu.mul[it_d->second]);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}