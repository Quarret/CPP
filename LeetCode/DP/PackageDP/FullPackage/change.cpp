#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector f(n + 1, vector<unsigned>(amount + 1, 0));
    
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int x = coins[i];
        for (int j = 0; j <= amount; j++) {
            if (j >= x) f[i + 1][j] = f[i][j] + f[i + 1][j - x];
            else f[i + 1][j] = f[i][j];
        }
    }

    return f[n][amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<unsigned> f(amount + 1, 0);

    f[0] = 1;
    for (int x : coins) {
        for (int c = x; c <= amount; c++) {
            f[c] = f[c] + f[c - x];
        }
    }

    return f[amount];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
