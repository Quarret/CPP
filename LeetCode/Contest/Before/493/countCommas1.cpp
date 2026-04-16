#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countCommas(long long n) {
    using ll = long long;
    ll flag1 = 1e3, flag2 = 1e6, flag3 = 1e9, flag4 = 1e12, flag5 = 1e15;
    
    ll ans = 0;
    ans += max(min(flag2 - flag1, n - flag1 + 1), 0LL);
    ans += 2 * max(min(flag3 - flag2, n - flag2 + 1), 0LL);
    ans += 3 * max(min(flag4 - flag3, n - flag3 + 1), 0LL);
    ans += 4 * max(min(flag5 - flag4, n - flag4 + 1), 0LL);
    if (n == flag5) ans += 5;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}