#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end(), [](auto &p1, auto &p2) {
        return p1[0] < p2[0];
    });
    
    int n = events.size();
    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], events[i][2]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = ranges::lower_bound(events, events[i][1], {}, [&](auto &p) {
            return p[0] - 1;
        }) - events.begin();

        ans = max(ans, events[i][2] + suf[j]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
