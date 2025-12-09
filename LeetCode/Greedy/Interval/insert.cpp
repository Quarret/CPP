#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    ranges::sort(intervals, {}, [](auto &p) {
        return p[1];
    });
    
    vector<vector<int>> ans;
    for (auto &p : intervals) {
        int l = p[0], r = p[1];
        if (ans.empty() || l > ans.back()[1]) {
            ans.push_back({l, r});
        } else {
            while (!ans.empty() && l <= ans.back()[1]) {
                l = min(l, ans.back()[0]);
                ans.pop_back();
            }
            ans.push_back({l, r});    
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
