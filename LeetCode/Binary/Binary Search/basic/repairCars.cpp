#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long repairCars(vector<int>& ranks, int cars) {
    long long maxx = *max_element(ranks.begin(), ranks.end());
    long long l = 1, r = maxx * cars * cars, n = ranks.size(), mid = 0;

    auto check = [&](long long k) -> bool {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(k / ranks[i]);
        }

        return ans >= cars;
    };

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (!check(mid)) l = mid + 1;
        else r = mid - 1; 
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
