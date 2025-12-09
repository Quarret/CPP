#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    ranges::sort(intervals, {}, [](auto &x) {
        return x[1];
    });
    
    vector<array<int, 3>> st = {{-2, -2, 0}};
    for (auto &interval : intervals) {
        int start = interval[0], end = interval[1];
        auto [_, r, s] = *--ranges::lower_bound(st, start, {}, [](auto &x) {
            return x[0];
        });

        int d = 2 - (st.back()[2] - s);
        if (start <= r) {
            d -= r - start + 1;
        }

        if (d <= 0) {
            continue;
        }

        while (end - st.back()[1] <= d) {
            auto [l, r, _] = st.back();
            st.pop_back();
            d += r - l + 1;
        }

        st.push_back({end - d + 1, end, st.back()[2] + d});
    }

    return st.back()[2];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
