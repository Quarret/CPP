#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countWays(vector<vector<int>>& ranges) {
    int n = ranges.size();
    ranges::sort(ranges, {}, [](auto &p) {
        return p[0];
    });
    
    int end = -1;
    long long ans = 1, MOD = 1e9 + 7;
    for (auto &p : ranges) {
        int l = p[0], r = p[1];
        if (l > end) {
            ans = (ans << 1) % MOD;
        }
        end = max(end, r);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
