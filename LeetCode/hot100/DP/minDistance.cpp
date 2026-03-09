#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector memo(n, vector<int>(m, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0) { // s 为空
            return j + 1; // 插入 j + 1 个与 t 相同的字符
        }
        if (j < 0) {
            return i + 1;
        }

        int &res = memo[i][j];
        if (res != -1) return res;

        if (s[i] == t[j]) {
            res = dfs(i - 1, j - 1);
        } else {
            // 删除, 插入, 替换 
            res = min({dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1, j - 1)}) + 1;
        }

        return res;
    };

    return dfs(n - 1, m - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}