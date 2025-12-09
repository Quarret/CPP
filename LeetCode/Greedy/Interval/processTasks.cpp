#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int processTasks(vector<vector<int>>& tasks) {
    ranges::sort(tasks, {}, [](auto &p) {
        return p[1];
    });

    vector<array<int, 3>> st = {{-2, -2, 0}};
    for (auto &task : tasks) {
        int start = task[0], end = task[1], d = task[2];
        auto [_, r, s] = *--ranges::lower_bound(st, start, {}, [](auto &p) {
            return p[0];
        });

        d -= st.back()[2] - s;
        if (start <= r) {
            d -= r - start + 1;
        }

        if (d <= 0) {
            continue;
        }

        while (end - st.back()[1] <= d) {
            auto [l, r, _] = st.back();
            d += r - l + 1;
            st.pop_back();
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
