#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long maxx = *max_element(workerTimes.begin(), workerTimes.end());
    long long l = 1, r = maxx * (1 + mountainHeight) * mountainHeight/ 2;
    long long n = workerTimes.size(), mid = 0;
    
    auto check = [&](long long k) -> bool {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(2 * k / workerTimes[i]);
        }

        return ans >= mountainHeight;
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
