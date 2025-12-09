#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    vector f(n + 1, vector<int>(amount + 1, 1e9));
    f[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (j >= coins[i]) f[i + 1][j] = min(f[i][j], f[i + 1][j - coins[i]] + 1);
            else f[i + 1][j] = f[i][j];
        }
    }

    return f[n][amount] == 1e9 ? -1 : f[n][amount];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> f(amount + 1, 1e9);

    f[0] = 0;
    for (int x : coins) {
        for (int c = x; c <= amount; c++) {
            f[c] = min(f[c], f[c - x]);
        }
    }

    return f[amount] == 1e9 ? -1 : f[amount];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
