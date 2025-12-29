#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    int ans = 0;
    for (auto &e : grid) {
        ranges::reverse(e);
        ans += ranges::upper_bound(e, -1) - e.begin();
    }

    return ans;
}

// 数学
int countNegatives(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int i = 0, j = n - 1, ans = 0;
    while (i < m && j >= 0)
    {
        if (grid[i][j] < 0)
        {
            ans += m - i;
            j--;
        }
        else
        {
            i++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 这道题与位置无关吗? 可以先排序吗?
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 看到一些熟悉的性质? 试试从性质中的变量出发
4. 正面难做难想吗? 要不试试反面? 正逆序都试试
5. 此题有单调性吗? 可以二分答案吗?
6. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
7. 贡献法可以做吗?
8. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/