#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 注意到删除前后都是等差数列
long long lastInteger(long long n) {
    long long st = 1, d = 1;
    while (n > 1) {
        st = st + (n % 2 ? n - 1 : n - 2)  * d;
        d *= -2;
        n = (n + 1) / 2;
    } 

    return st;
}

long long lastInteger(long long n) {
    long long mask = 0xAAAAAAAAAAAAAAAA;
    return ((n - 1) & mask) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
