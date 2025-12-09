#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isPowerOfFour(int n) {
    int cnt = __bit_width(n);
    
    return __builtin_popcount(n) == 1 && cnt % 2 == 1; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
