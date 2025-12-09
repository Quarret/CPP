#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int leastMinutes(int n) {
    int ans = INT_MAX, x = 1;
    for (int i = 0; i <= __bit_width(n); i++) {
        ans = min(ans, i + (n + x - 1) / x);
        x <<= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
