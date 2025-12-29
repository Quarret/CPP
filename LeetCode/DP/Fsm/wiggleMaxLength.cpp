#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    // memo[i][j] 表示前 i 个数字中最后趋势为 j 的最长子序列
    vector f(n + 1, array<int, 2>{-1, -1});
    f[0][0] = f[0][1] = 1;
    for (int i = 1; i < n; i++) {
        f[i][0] = f[i][1] = 1;

        for (int j = 0; j < i; j++) {
            if (nums[i] < nums[j]) {
                f[i][0] = max(f[i][0], f[j][1] + 1);
            }
        }

        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                f[i][1] = max(f[i][1], f[j][0] + 1);
            }
        }
    }

    return max(f[n - 1][0], f[n - 1][1]);
}

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    vector f(n + 1, array<int, 2>{-1, -1});
    f[1][0] = f[1][1] = 1;
    for (int i = 1; i < n; i++) {
        // 贪心的想: 当 nums[i - 1] < nums[i] 时, 越长的区间连接出来的摆动序列越长, 故选择f[i][0]
        if (nums[i] > nums[i - 1]) {
            f[i + 1][1] = max(f[i][1], f[i][0] + 1);
        } else if (nums[i] < nums[i - 1]) {
            f[i + 1][0] = max(f[i][0], f[i][1] + 1);
        } else {
            f[i + 1][0] = f[i][0];
            f[i + 1][1] = f[i][1];
        }
    }

    return max(f[n][0], f[n][1]);
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