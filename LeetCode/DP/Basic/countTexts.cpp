#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countTexts(string pressedKeys) {
    unordered_map<int, vector<int>> g;
    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 3; j++) {
            g[i].push_back(j);
        }
    }
    g[7].push_back(4);
    g[9].push_back(4);
    
    int n = pressedKeys.size(), MOD = 1e9 + 7;
    vector<int> f(n + 1);
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        char c = pressedKeys[i - 1];
        for (int x : g[c - '0']) {
            if (i - x < 0 || pressedKeys[i - x] != c) break;
            f[i] = (f[i] + f[i - x]) % MOD;
        }
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
