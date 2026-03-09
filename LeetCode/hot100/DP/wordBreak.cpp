#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 划分型 DP s[0:i - 1] 是子问题
bool wordBreak(string s, vector<string>& wordDict) {
    int max_len = ranges::max(wordDict, {}, &string::size).size();
    unordered_set<string> words(wordDict.begin(), wordDict.end());

    int n = s.size();
    vector<int> memo(n + 1, -1);

    auto dfs = [&](this auto&& dfs, int i) -> bool {
        if (i == 0) {
            return true;
        }

        int &res = memo[i];
        if (res != -1) return res;

        for (int j = i - 1; j >= (i - max_len, 0); j--) {
            if (words.contains(s.substr(j, i - j)) && dfs(j)) {
                return res = true;
            }
        }

        return res = false;
    };

    return dfs(n);
}

// 递推
bool wordBreak(string s, vector<string>& wordDict) {
    int max_len = ranges::max(wordDict, {}, &string::size).size();
    unordered_set<string> words(wordDict.begin(), wordDict.end());

    int n = s.size();
    vector<bool> f(n + 1);
    f[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= max(i - max_len, 0); j--) {
            if (words.contains(s.substr(j, i - j)) && f[j]) {
                f[i] = true;
            }
        }
    }

    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}