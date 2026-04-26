#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int mirrorDistance(int n) {
    int res = 0;
    int k = n;
    while (k) {
        res = res * 10 + k % 10;
        k /= 10;
    }
    
    return abs(n - res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}