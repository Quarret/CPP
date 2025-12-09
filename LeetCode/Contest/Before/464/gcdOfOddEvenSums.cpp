#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int gcdOfOddEvenSums(int n) {
    int even = 0, odd = 0;
    for (int i = 1; i <= 2 * n; i++) {
        (i % 2 ? odd : even) += i;
    }
    
    return gcd(even, odd);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
