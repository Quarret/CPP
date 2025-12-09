#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long flowerGame(int n, int m) {
    long long even1 = 1LL * n / 2, odd1 = (1LL * (n + 1) / 2);
    long long even2 = 1LL * m / 2, odd2 = (1LL * (m + 1) / 2);

    return even1 * odd2 + even2 * odd1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
