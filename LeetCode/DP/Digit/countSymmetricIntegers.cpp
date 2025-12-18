#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSymmetricIntegers(int low, int high) {
    string low_s = to_string(low);
    string high_s = to_string(high);
    int n = high_s.size();
    int diff_lh = n - low_s.size();
    
    // start <= diff_lh, 不然就会比 low 小
    vector memo(n, vector(diff_lh + 1, vector<int>(n / 2 * 9 + 1, -1)));
    // 这种关于两个变量加减的参数可以压缩到 "两变量之差" 一个参数 diff
    // start 记录填入的第一位数字的位置, 当 is_num 使用
    auto dfs = [&](this auto&& dfs, int i, int start, int diff, bool limit_low, bool limit_high) -> int {
        if (diff < 0) {
            return 0;
        }

        if (i == n) {
            return diff == 0;
        }

        if (start != -1 && !limit_low && !limit_high && memo[i][start][diff] != -1) {
            return memo[i][start][diff];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        // 前面还没填数字, 填入后是奇数位数字, 不合法
        if (start < 0 && (n - i) % 2) {
            // 如果必须返回数字 (lo > 0), 不合法, 返回 0
            return lo > 0 ? 0 : dfs(i + 1, start, diff, true, false);
        }   

        int res = 0;
        // 是否在左半边
        bool is_left = start < 0 || i < (start + n) / 2;
        for (int d = lo; d <= hi; d++) {
            res += dfs(i + 1,
                       start < 0 && d > 0 ? i : start,
                       diff + (is_left ? d : -d), // 不要再犯 diff += .. 的错误了, 排查了半天 
                       limit_low && d == lo,
                       limit_high && d == hi); // 先进入 dfs, 直接排除 diff 为负的情况
        }

        if (start != -1 && !limit_low && !limit_high) {
            cout << diff << '\n';
            memo[i][start][diff] = res;
        }
        return res;
    };

    return dfs(0, -1, 0, true, true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
