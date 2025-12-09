#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    int n = points.size();
    int l = 0, mid = 0, r = 0;
    for (int i = 0; i < n; i++) {
        r = max(r, max(abs(points[i][0]), abs(points[i][1])));
    }
    r++;

    auto check = [&](int k) -> bool {
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            if (abs(points[i][0]) <= k && abs(points[i][1]) <= k) {
                if (cnt[s[i] - 'a']) return 0;
                else cnt[s[i] - 'a']++;
            } 
        }

        return 1;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (abs(points[i][0]) <= l && abs(points[i][1]) <= l) ans++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
