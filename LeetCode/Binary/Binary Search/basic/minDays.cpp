#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minDays(vector<int>& bloomDay, int m, int k) {
    long long l = 1, r = *max_element(bloomDay.begin(), bloomDay.end()), n = bloomDay.size(), mid = 0;

    if (n < (long long)m * k) return -1;

    auto check = [&](long long t) -> bool {
        int ans = 0, num = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= t) num++;
            else num = 0;

            if (num == k) {
                ans++;
                num = 0;
            }
        }

        return ans >= m;
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
