#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 带权并查集, A -> B 边权异或相同
class UnionFind {
public:
    vector<int> fa;
    vector<int> dis; // dis[x] 表示 x 到代表根的边权异或和
    
    UnionFind(int n) : fa(n), dis(n) {
        ranges::iota(fa, 0);
    }

    int find(int x) {
        if (fa[x] != x) {
            int root = find(fa[x]);
            dis[x] ^= dis[fa[x]]; // 归的过程中更新边权和
            fa[x] = root;
        }

        return fa[x];
    }
    
    bool merge(int from, int to, int value) {
        int x = find(from), y = find(to);
        // 在同一个集合
        if (x == y) {
            // A -> root 和 B -> root 会重复一段, 设相交点为 C, C -> root 异或相抵
            return (dis[from] ^ dis[to]) == value;
        }

        // 不在同一个集合, 不成环但满足题目条件
        dis[x] = dis[from] ^ value ^ dis[to];
        fa[x] = y;
        return true;
    }
};


class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    
    int ans = 0;
    for (auto &e : edges) {
        if (uf.merge(e[0], e[1], e[2])) {
            ans++;
        }
    }

    return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}