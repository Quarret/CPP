#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
    
const int MX = 100'001;
vector<int> divide[MX]; // c 风格的初始化
// 这种写法的 lambda 在 main 调用之前执行
int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) {
            divide[j].push_back(i);
        }
    }

    return 0;   
}();


class Solution {
public:
vector<int> minDifference(int n, int k) {
    int min_diff = INT_MAX;
    vector<int> path(k), ans;

    auto dfs = [&](this auto&& dfs, int i, int n, int mn, int mx) -> void {
        // 没有空余的因子位置, 只能是 n
        if (i == k - 1) { 
            int d = max(mx, n) - min(mn, n);
            if (d < min_diff) {
                min_diff = d;
                path[i] = n;
                ans = path;
            }

            return;
        }

        for (int d : divide[n]) {
            path[i] = d;
            dfs(i + 1, n / d, min(mn, d), max(mx, d));
        }
    };

    dfs(0, n, INT_MAX, 0);
    return ans;
}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
