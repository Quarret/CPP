#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


long long sumAndMultiply(int n) {
    long long s = 0, base = 0, pow = 1;
    while (n) {
        long long res = n % 10;
        if (res) {
            base = base + res * pow;
            pow *= 10;
            s += res;
        }
        n /= 10;
    }
    
    return base * s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
