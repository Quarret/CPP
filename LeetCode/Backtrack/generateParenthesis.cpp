#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 平衡字符串, 左括号和右括号个数相同都为 n
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int m = 2 * n;
    string path(m, ' ');

    auto dfs = [&](this auto&& dfs, int i, int left) -> void {
        if (i == m) {
            ans.push_back(path);
            return;
        }

        if (left < n) {
            path[i] = '(';
            dfs(i + 1, left + 1);
        }

        // 左右括号和为 i, 右括号的个数小于左括号就可以选一个右括号
        if (i + 1 - left < left) {
            path[i] = ')';
            dfs(i + 1, left);
        }
    };

    dfs(0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
