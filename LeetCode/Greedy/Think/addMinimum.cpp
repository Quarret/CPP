#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int addMinimum(string word) {
    int n = word.size();
    int cnt_abc = 0, cnt_ab = 0, cnt_ac = 0, cnt_bc = 0;

    for (int i = 2; i < n; i++) {
        if (word[i - 2] == 'a' && word[i - 1] == 'b' && word[i] == 'c') {
            cnt_abc++;
        } 
    }

    for (int i = 1; i < n; i++) {
        if ((word[i - 1] == 'a' && word[i] == 'b')) {
            cnt_ab++;
        } else if ((word[i - 1] == 'b' && word[i] == 'c')) {
            cnt_bc++;
        } else if (word[i - 1] == 'a' && word[i] == 'c') {
            cnt_ac++;
        }
    }

    cnt_ab -= cnt_abc;
    cnt_bc -= cnt_abc;
    return (n - 3 * cnt_abc - 2 * (cnt_ab + cnt_ac + cnt_bc)) * 2 + (cnt_ab + cnt_ac + cnt_bc);
}

// 考虑相邻字母
int addMinimum(string word) {
    int n = word.size();
    int ans = word[0] + 2 - word.back();

    for (int i = 1; i < n; i++) {
        ans += (word[i] - word[i - 1] + 2) % 3;
    }
    return ans;
}

// 统计 abc 个数
// s[i] >= s[i + 1] 则不在同一个 abc
int addMinimum(string word) {
    int n = word.size(), t = 1; // 至少为 1
    for (int i = 0; i < n - 1; i++) {
        t += word[i] >= word[i + 1];
    }

    return 3 * t - n;
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