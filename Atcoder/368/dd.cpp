#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<int>> adj(N);//adj邻接矩阵维护树
    for (int i = 1; i < N; i++) {
        int A, B;
        std::cin >> A >> B;
        A--;
        B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    std::vector<int> f(N), sum(N);//f是需要点数组，sum[i]代表以这个点为根的树中有多少题目需要的节点
    for (int i = 0; i < K; i++) {
        int V;
        std::cin >> V;
        V--;
        f[V] = 1;
    }
    int ans = 0;
    auto dfs = [&](auto &self, int x, int p) -> void {
        sum[x] = f[x];
        int ch = 0;
        if (f[x] == 1) {
            ch += 2;//子节点为需要节点，需要父节点，
        }
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(self, y, x);
            sum[x] += sum[y];
            if (sum[y] > 0) {
                ch++;
            }
        }
        if (sum[x] < K) {
            ch++;
        }
        if (ch >= 2) {
            ans++;
        }
    };
    dfs(dfs, 0, -1);
    
    std::cout << ans << "\n";
    
    return 0;
}