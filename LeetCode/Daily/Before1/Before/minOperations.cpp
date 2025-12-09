#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minOperations(vector<vector<int>>& queries) {
    auto f = [&](int n) -> long long {
        int m = __bit_width(n);
        long long res = 0;

        for (int i = 1; i < m; i++) {
            res += 1LL * (i + 1) / 2 * (1LL << (i - 1));
        }

        return res + 1LL * (m + 1) / 2 * ((n - (1 << m) / 2) + 1);
    };
    
    long long ans = 0;
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        ans += ((f(r) - f(l - 1)) + 1) / 2;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
