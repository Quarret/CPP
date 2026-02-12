#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool pyramidTransition(string bottom, vector<string>& allowed) {
    int n = bottom.size();
    unordered_map<string, vector<char>> mp;
    for (auto s : allowed) {
        mp[s.substr(0, 2)].push_back(s[2]);
    }

    unordered_set<string> vis;

    auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
        if (i == n - 1) {
            return true;
        }

        if (i + j == n - 1) {
            if (vis.insert(bottom).second == false) {
                return false;
            }

            if (dfs(i + 1, 0)) {
                return true;
            }
        }

        for (char c : mp[bottom.substr(j, 2)]) {
            char ch = bottom[j];
            bottom[j] = c;
            if (dfs(i, j + 1)) {
                return true;
            }
            bottom[j] = ch;
        }

        return false;
    };

    return dfs(0, 0);
}

// 很傻的做法, 即回溯层也回溯上层字符串
bool pyramidTransition(string bottom, vector<string>& allowed) {
    int n = bottom.size();
    unordered_map<string, vector<char>> mp;
    for (auto s : allowed) {
        mp[s.substr(0, 2)].push_back(s[2]);
    }

    auto dfs = [&](this auto&& dfs, int i, string path) -> bool {
        if (i == n) {
            return true;
        }

        string upper(n - i - 1, ' ');
        vector<string> res;
        auto f = [&](this auto&& f, int j) -> void {
            if (j == n - i - 1) {
                res.push_back(upper);
                return;
            }

            string s = path.substr(j, 2);
            if (mp.find(s) == mp.end()) return;
            for (auto &c : mp[s]) {
                upper[j] = c;
                f(j + 1);
            }
        };

        f(0);
        if (res.empty()) return false;

        for (auto &up : res) {
            if (dfs(i + 1, up)) {
                return true;
            }
        }

        return false;
    };

    return dfs(0, bottom);
}

// 记忆化: 所有状态转移都在金字塔上, 创建金字塔
bool pyramidTransition(string bottom, vector<string>& allowed) {
    unordered_map<string, vector<char>> mp;
    for (auto &a : allowed) {
        mp[a.substr(0, 2)].push_back(a[2]);
    }

    int n = bottom.size();
    vector<string> pyramid(n);
    for (int i = 0; i < n; i++) {
        pyramid[i].resize(i + 1);   
    }
    pyramid[n - 1] = move(bottom);

    unordered_set<string> vis;

    auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
        if (i == 0) {
            return true;
        }

        if (vis.contains(pyramid[i - 1]))
        { // 之前填过这个字符串, 没成功
            return false;
        }

        if (i == j)
        {
            vis.insert(pyramid[i - 1]);

            if (dfs(i - 1, 0)) {
                return true;
            }
        }

        for (char c : mp[pyramid[i].substr(j, 2)]) {
            pyramid[i - 1][j] = c;
            if (dfs(i, j + 1)) {
                return true;
            }
        }

        return false;
    };

    return dfs(n - 1, 0);
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