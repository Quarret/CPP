#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int sum = accumulate(apple.begin(), apple.end(), 0);
    ranges::sort(capacity, greater());

    int n = capacity.size();
    for (int i = 0; i < n; i++) {
        sum -= min(capacity[i], sum);
        if (sum == 0) {
            return i + 1;
        }
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 正面难做难想吗? 要不试试反面? 正逆序都试试
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 此题有单调性吗? 可以二分答案吗?
4. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
5. 贡献法可以做吗?
6. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/