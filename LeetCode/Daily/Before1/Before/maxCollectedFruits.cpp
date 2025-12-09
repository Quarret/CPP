#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
这题学习灵神的记忆化搜索：
要求每个小孩只能走n - 1步到达(n - 1, n- 1)
所以(0, 0)小孩只能走主对轴线
其余两个小孩不能超过主对轴线
由于(n - 1, n - 1)已经由小孩一获得,先算(0, n - 1)小孩到(n - 2, n - 1)的最大值，然后表格沿主对轴线反转算原(n - 1, 0)
由于我们是倒着走的，思考原(0, n - 1)时我们不能超过此点的左下对轴线 i + j == n - 1这条，倒着走也需满足

记忆化搜索 == 可递推的dfs(?)
*/
int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size();
    vector<vector<int>> vis(n, vector<int>(n, -1));
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (j < n - 1 - i || j >= n) return 0;
        if (i == 0) return fruits[i][j];//only (0, n- 1)

        int &res = vis[i][j];//notice the &, it will change the vis[i][j]
        if (res != - 1) return res;
        return res = max({dfs(i - 1, j - 1), dfs(i - 1, j), dfs(i - 1, j + 1)}) + fruits[i][j];
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += fruits[i][i];
    }

    ans += dfs(n - 2, n - 1);

    //将左下角数据倒转到右上角三角形，重复利用代码
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            fruits[j][i] = fruits[i][j];
        }
    }

    ranges::fill(vis, vector(n, -1));//refresh vis
    return ans + dfs(n - 2, n - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
