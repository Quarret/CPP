#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumOneBitOperations(int n) {
    if (n == 0) {
        return 0;
    }

    int x = __bit_width(n) - 1;
    return (1 << x) - 1 - minimumOneBitOperations(n - (1 << x));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
