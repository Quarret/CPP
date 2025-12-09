#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    ranges::sort(points, {}, [](auto &p) {
        return p[1];
    });
    
    long long ans = 0, pre_r = INT64_MIN;
    for (auto &p : points) {
        if (p[0] > pre_r) {
            ans++;
            pre_r = p[1];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
