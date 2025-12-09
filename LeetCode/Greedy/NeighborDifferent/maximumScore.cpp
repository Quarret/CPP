#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumScore(int a, int b, int c) {
    int n = a + b + c, m = max({a, b, c});
    return min(n / 2, n - m);        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
