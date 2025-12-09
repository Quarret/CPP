#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector f(n + 1, vector<int>(4, INT32_MAX));
    
    f[1][2] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (obstacles[i] == j + 1) continue;
            f[i + 1][j + 1] = f[i][j + 1]; 
        }

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i + 1][k + 1] + (j != k));
            }
        }
    }

    return min({f[n][1], f[n][2], f[n][3]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
