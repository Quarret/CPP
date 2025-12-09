#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int preimageSizeFZF(int k) {
    long long l = -1, r = 10 * k + 1, mid = 0;

    auto check = [&](long long t, long long cntx) {
        long long cnt = 0;
        long long div5 = 5, div10 = 10;
        /*
        25中因数有两个5!!! 100因数中有2个10!!!
        */
        while (t / div5 != 0 || t / div10 != 0) {
            cnt += t /div10;
            cnt += t / div5 - t / div10;
            div5 *= 5;
            div10 *= 10;
        }

        if (cnt >= cntx) return 1;
        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid, k) ? r : l) = mid;
    }

    long long l1 = -1, r1 = (k + 1) * 10 + 1, mid1 = 0;

    while (l1 + 1 < r1) {
        mid1 = l1 + (r1 - l1) / 2;
        (check(mid1, k + 1) ? r1 : l1) = mid1;
    }

    return r1 - r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    preimageSizeFZF(0);

    return 0;
}
