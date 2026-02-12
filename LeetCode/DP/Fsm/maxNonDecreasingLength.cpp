#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> nums(2);
    nums[0] = nums1;
    nums[1] = nums2;
    
    vector memo(n, array<int, 2>{-1, -1});
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i == 0) {
            return 1;
        }

        int &res = memo[i][j];
        if (res != -1) {
            return res;
        }

        res = 1;
        if (nums1[i - 1] <= nums[j][i]) {
            res += dfs(i - 1, 0);
        }
        if (nums2[i - 1] <= nums[j][i]) {
            res = max(res, dfs(i - 1, 1) + 1);
        }

        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    return ans;
}

int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> nums(2);
    nums[0] = nums1;
    nums[1] = nums2;
    
    int ans = 1;
    vector f(n + 1, vector<int>(2, 1));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (nums1[i - 1] <= nums[j][i]) {
                f[i + 1][j] = f[i][0] + 1;
            }
            if (nums2[i - 1] <= nums[j][i]) {
                f[i + 1][j] = max(f[i + 1][j], f[i][1] + 1);
            }
            
            ans = max(ans, f[i + 1][j]);
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
4. 试着从循环不变量着手思考
5. 正面难做难想吗? 要不试试反面? 正逆序都试试
6. 此题有单调性吗? 可以二分答案吗?
7. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
8. 贡献法可以做吗?
9. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/