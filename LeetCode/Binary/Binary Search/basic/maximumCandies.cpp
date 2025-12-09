#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumCandies(vector<int>& candies, long long k) {
    long long l = 0, r = *min_element(candies.begin(), candies.end()) + 1, n = candies.size(), mid = 0;
    
    auto check = [&](long long k) -> bool {
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += candies[i] / k;

        return ans >= k;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
