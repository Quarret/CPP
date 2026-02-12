#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<string>> wordSquares(vector<string>& words) {
    int n = words.size();
    ranges::sort(words);
    vector<vector<string>> ans;
    
    for (int i = 0; i < n; i++) {
        string top = words[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            string bottom = words[j];

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                string left = words[k];

                for (int t = 0; t < n; t++) {
                    if (t == i || t == j || t == k) continue;
                    string right = words[t];

                    if (top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3]) {
                        ans.push_back({top, left, right, bottom});
                    }
                }
            }
        }
    }

    sort(ans.begin(), ans.end(), [](auto &a, auto&b) {
        for (int i = 0; i < 4; i++) {
            if (a[i] < b[i]) return true;
            else if (a[i] > b[i]) return false;
        }
        return false;
    });

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

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