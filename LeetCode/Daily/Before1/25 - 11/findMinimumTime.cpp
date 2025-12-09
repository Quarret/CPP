#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 区间问题一律采用右端点排序
int findMinimumTime(vector<vector<int>>& tasks) {
    ranges::sort(tasks, {}, [](auto &a) {
        return a[1];
    });
    
    // [闭区间左端点, 闭区间右端点, 不相交区间已运行任务前缀和]
    vector<array<int, 3>> st = {{-2, -2, 0}}; // 初始化, 保证不与任何区间相交
    for (auto task: tasks) {
        int start = task[0], end = task[1], d = task[2];
        // 查找 start 在的 区间
        auto [_, r, s] = *--ranges::lower_bound(st, start, {}, [](auto &x) {
            return x[0];
        });

        // 减去已使用时间
        d -= st.back()[2] - s;
        if (start <= r) {
            // start 在的区间中使用的时间
            d -= r - start + 1;
        }

        if (d <= 0) {
            continue;
        }

        // 填充剩余的 d 
        while (end - st.back()[1] <= d) {
            auto [l, r, _] = st.back();
            st.pop_back();
            d += r - l + 1;
        }

        // st.emplace_back(end - d + 1, end, st.back()[2] + d);
        st.push_back({end - d + 1, end, st.back()[2] + d});
    }

    return st.back()[2];
}

// 暴力模拟
int findMinimumTime(vector<vector<int>>& tasks) {
    ranges::sort(tasks, {}, [](auto &a) {
        return a[1];
    });
    
    int ans = 0;
    vector<int> run(tasks.back()[1] + 1);
    for (auto &t : tasks) {
        int start = t[0], end = t[1], d = t[2];
        d -= reduce(run.begin() + start, run.begin() + end + 1);
        for (int i = end; d > 0; i--) {
            if (!run[i]) {
                run[i] = 1;
                ans++;
                d--;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
