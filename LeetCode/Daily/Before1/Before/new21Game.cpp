#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double new21Game(int n, int k, int maxPts) {
    vector<double> memo(n + 1, -1);

    auto dfs = [&](this auto&& dfs, int x) -> double {
        if (x > n) return 0.0;
        if (x >= k) return 1.0;

        double &res = memo[x];
        if (res != -1.0) return memo[x];
        else {
            res = 0.0;
            for (int i = 1; i <= maxPts; i++) {
                res += dfs(x + i) / maxPts;
            }
        }
        
        return res;
    };

    return dfs(0);
}

//sliding windows + dp
//status init: f[i] : the chance from i to [k, n]
//status move: f[i] = (f[i + 1] + ... + f[i + maxpts]) / maxpts
//due to the v is bigger than u, so enumrate from big to small
//the status move is sliding windows
double new21Game(int n, int k, int maxPts) {
    vector<double> memo(n + 1);
    
    double s = 0;
    for (int i = n; i >= 0; i--) {
        memo[i] = i >= k ? 1 : s / maxPts;
        // cur : s = memo[i + 1] + .. + memo[i + maxpts]
        
        s += memo[i];
        if (i + maxPts <= n) s -= memo[i + maxPts];
    }

    return memo[0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
