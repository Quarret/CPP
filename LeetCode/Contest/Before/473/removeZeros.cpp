#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long removeZeros(long long n) {
    long long ans = 0, base = 1;
    while (n) {
        if (n % 10 != 0) {
            ans = ans + (n % 10) * base;
            base *= 10;
        }
        n /= 10;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
