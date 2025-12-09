#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minimumTime(vector<int>& d, vector<int>& r) {
    long long d1 = d[0], d2 = d[1];
    long long r1 = r[0], r2 = r[1];
    long long L = lcm(r1, r2);

    auto check = [&](long long t) -> bool {
        return d1 <= t - t / r1 
                && d2 <= t - t / r2 
                && d1 + d2 <= t - t / L; 
    };

    long long left = 0, right = 1e10;
    while (left + 1 < right) {
        long long mid = left + (right - left) / 2;
        (check(mid) ? right : left) = mid;
    }

    return right;
}

long long minimumTime(vector<int>& d, vector<int>& r) {
    long long d1 = d[0], d2 = d[1];
    long long r1 = r[0], r2 = r[1];
    long long L = lcm(r1, r2);

    auto f = [&](long long x, long long y) -> long long {
        return x + (x - 1) / (y - 1);
    };

    return max({f(d1, r1), f(d2, r2), f(d1 + d2, L)});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
