#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    vector f(n + 1, vector<int>(amount + 1, 1e9));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int c = coins[i];
        for (int j = 0; j <= amount; j++) {
            if (j >= c) f[i + 1][j] = min(f[i][j], f[i + 1][j - c] + 1);
            else f[i + 1][j] = f[i][j];
        }
    }

    return f[n][amount] == 1e9 ? -1 : f[n][amount];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}