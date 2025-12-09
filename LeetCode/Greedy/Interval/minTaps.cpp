#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> a;
    for (int i = 0; i <= n; i++) {
        int l = max(0, i - ranges[i]);
        int r = min(n, i + ranges[i]);
        if (ranges[i] != 0) {
            a.emplace_back(l, r);
        }
    }
    
    ranges::sort(a, {}, [](auto &p) {
        return p.first;
    });

    int ans = 0, j = 0;
    int cur_r = 0, next_r = 0;
    for (int i = 0; i < n; i++) {
        while (j < a.size() && a[j].first <= i) {
            next_r = max(next_r, a[j].second);
            j++;
        }

        if (i == cur_r) {
            ans++;
            cur_r = next_r;
        }
    }

    return cur_r >= n ? ans : -1;
}

int minTaps(int n, vector<int>& ranges) {
    vector<int> right_most(n + 1);
    for (int i = 0; i <= n; i++) {
        int r = ranges[i];
        int left = max(0, i - r);
        right_most[left] = max(right_most[left], r + i);
    }

    int ans = 0;
    int cur_r = 0, next_r = 0;
    for (int i = 0; i < n; i++) {
        next_r = max(next_r, right_most[i]);
        if (i == cur_r) {
            // 没有远的桥来走
            if (cur_r == next_r) {
                return -1;
            }

            ans++;
            cur_r = next_r;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
