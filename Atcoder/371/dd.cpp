#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<int> X(N), P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }
    std::vector<i64> pre(N + 1);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] + P[i];
    }
    
    int Q;
    std::cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        R++;
        
        int l = std::lower_bound(X.begin(), X.end(), L) - X.begin();
        int r = std::lower_bound(X.begin(), X.end(), R) - X.begin();
        std::cout << pre[r] - pre[l] << "\n";
    }
    
    return 0;
}