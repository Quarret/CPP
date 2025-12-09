#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int mySqrt(int x) {
    int l = 0, r = x + 1, mid = 0;

    auto check = [&](int k) {
        return k * k <= x;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    };

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
