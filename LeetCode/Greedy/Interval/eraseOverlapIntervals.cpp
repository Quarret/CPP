#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        if (a[1] < b[1]) return true;
        else if (a[1] == b[1]) {
            return a[0] < b[0];
        }

        return false;
    });
    
    int right = -50005, ans = 0;
    for (auto &interval : intervals) {
        int l = interval[0], r = interval[1];
        if (l < right) {
            ans++;
            continue;
        }
        right = r;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
