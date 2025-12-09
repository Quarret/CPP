#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
本题可以贪心的来想，对于连续的1 加上lowbit对于减去两个1来说更赚，因为后续生成的1可能会更有益的影响后续操作,对于单独的1 加lowbit无意义
我一开还在想整体计算连续1，但其实小部分计算就行，局部最优就是全局最优
*/
int minOperations(int n) {
    int ans = 1;
    while (n & (n - 1)) {
        int lowbit = n & -n;
        if (n & (lowbit << 1)) n += lowbit;
        else n -= lowbit;
        ans++;
    }

    return ans;
}

/*
灵神的暴力搜索，不要把dfs局部在grid表中
*/

int minOperations(int n) {
    auto dfs = [&](this auto& dfs, int x) -> int {
        if ((x & (x - 1)) == 0) return 1;
        int lowbit = x & -x;

        return 1 + min(dfs(x + lowbit), dfs(x - lowbit));
    };

    return dfs(n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
