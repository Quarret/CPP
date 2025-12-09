#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
概率dp还不会，看了灵神的题解 -> 记忆化搜索
由于各个事件都是等概率发生，所以状态转移方程：
dfs(a, b) = 0.25 * (dfs(a - 100, b) + dfs(a - 75, b - 25) + dfs(a - 50, b - 50) + dfs(dfs - 25, b - 75));
计算期望我们可知 E(a) = 67.5 E(b) = 37.5 所以在当n越大，取的回合越多，a比b先耗尽的概率就越大,存在阈值4451时，后续概率都为1
由于取的都是25的整倍数，所以我们按(n + 25) / 25分快来减小内存空间
记忆化搜索 = 递归搜索 + 记录返回值
*/
double soupServings(int n) {
    if (n >= 5000) return 1.0;
    
    n = (n + 24) / 25;
    vector memo(n + 1, vector<double>(n + 1, 0));

    auto dfs = [&](this auto&& dfs, int a, int b) -> double {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 1.0;

        double &res = memo[a][b];
        if (res == 0) {
            res = (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3)) / 4; 
        }
        return res;
    };

    return dfs(n, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
