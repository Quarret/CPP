#include <bits/stdc++.h>
using ll = long long;
using namespace std;


class UnionFind {
public:
    vector<int> fa;
    vector<int> dis; // dis[x]: x 到代表元的哈密顿距离

    UnionFind(int n) : fa(n), dis(n) {
        ranges::iota(fa, 0);
    }

    int find(int x) {
        if (x != fa[x]) {
            int root = find(fa[x]);
            dis[x] += dis[fa[x]];
            fa[x] = root;
        }
        return fa[x];
    }

    bool merge(int from, int to, int value, int k) {
        int x = find(from), y = find(to);
        if (x == y) {
            return abs(dis[from] - dis[to])
        }
    }
};

class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}