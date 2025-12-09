#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();

    auto check = [&](long long x) -> bool {
        long long s = 0, cnt = k;
        vector<int> a(stations.begin(), stations.end());
        for (int j = -r; j < n + r; j++) {
            if (j < 0 || j >= n) s += 0;
            else s += 1LL * a[j];

            if (j < r - 1) continue;

            if (s < x) {
                if (cnt < x - s) return false;
                long long diff = x - s;
                cnt -= diff;
                s = x;
                a[min(j, n - 1)] += diff;
            }
            
            int i = j - (2 * r + 1) + 1;
            s -= i < 0 ? 0 : 1LL * a[i];
        }

        return true;
    };
    
    long long left = *min_element(stations.begin(), stations.end());
    long long right = INT64_MAX / 2;

    while (left + 1 < right) {
        long long mid = left + (right - left) / 2;
        (check(mid) ? left : right) = mid;
    }

    return left;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
