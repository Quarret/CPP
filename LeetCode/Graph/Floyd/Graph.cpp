#include <bits/stdc++.h>
using ll = long long;
using namespace std;


class Graph {
public:
    int N;
    vector<vector<int>> w, f;

    Graph(int n, vector<vector<int>>& edges) 
        :   N(n),
            w(n, vector<int>(n, INT_MAX / 2)),
            f(n, vector<int>(n, INT_MAX / 2))

    {
        for (int i = 0; i < n; i++) w[i][i] = 0;
        for (auto &e : edges) {
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = wt;
        }
        
        // f = move(w) 会转移内存的所有权, 导致 w 为空
        f = w;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int x = edge[0], y = edge[1], wt = edge[2];
        if (wt >= w[x][y]) return;
        w[x][y] = wt;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                f[i][j] = min(1LL * f[i][j], 1LL * f[i][x] + wt + 1LL * f[y][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return f[node1][node2] == INT_MAX / 2 ? -1 : f[node1][node2];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}