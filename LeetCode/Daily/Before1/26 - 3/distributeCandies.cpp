#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 容斥原理
long long distributeCandies(int n, int limit) {
    using ll = long long;
    auto c2 = [&](ll n) -> ll {
        return n > 1 ? n * (n - 1) / 2 : 0;
    };

    return c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}