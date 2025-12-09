#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size(), l = 0, r = 0;
    sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });

    vector<vector<int>> ans;
    l = intervals.back()[0], r = intervals.back()[1];
    for (int i = n - 1; i >= 0; i--) {
        if (l > intervals[i][1]) {
            ans.push_back({l ,r});
            l = intervals[i][0];
            r = intervals[i][1];
        } else {
            l = min(l, intervals[i][0]);
        }
    }
    ans.push_back({l, r});

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
