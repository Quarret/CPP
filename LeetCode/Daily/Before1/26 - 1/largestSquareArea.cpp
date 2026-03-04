#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    int n = bottomLeft.size();
    
    int max_side = 0;
    for (int i = 0; i < n; i++) {
        auto &b1 = bottomLeft[i];
        auto &t1 = topRight[i];

        // 两相交矩形任意一个的长宽都小于等于 max_side, 最后围出来的矩形的长宽也一定不大于 max_side
        if (t1[0] - b1[0] <= max_side && t1[1] - b1[1] <= max_side) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            auto &b2 = bottomLeft[j];
            auto &t2 = topRight[j];

            int w = min(t1[0], t2[0]) - max(b1[0], b2[0]);
            int h = min(t1[1], t2[1]) - max(b1[1], b2[1]);
            max_side = max(max_side, min(w, h));
        }
    }

    return 1LL * max_side * max_side;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}