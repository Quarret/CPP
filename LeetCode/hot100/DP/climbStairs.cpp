#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int climbStairs(int n) {
    vector<int> f(n + 1);
    
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 1];
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
