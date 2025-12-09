#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    ranges::sort(intervals, [](auto &p1, auto &p2) {
        if (p1[0] < p2[0]) return true;
        else if (p1[0] == p2[0]) {
            return p1[1] > p2[1];
        }

        return false;
    });

    int end = -1, ans = 0;
    for (auto &p : intervals) {
        if (p[1] <= end) {
            ans++;
        }
        end = max(end, p[1]);
    }

    return intervals.size() - ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
