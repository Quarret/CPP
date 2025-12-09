#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool splitString(string s) {
    int n = s.size(), ok = 0;
    vector<long long> path;

    auto dfs = [&](this auto&& dfs, int i, int start) -> void {
        if (i == n) {
            if (path.size() > 1) ok = 1;
            return;
        }

        if (i < n - 1) {
            dfs(i + 1, start);
        }

        string t = s.substr(start, i - start + 1);
        long long num = stoll(t);
        if (num > pow(10, 11)) return;
        if (path.empty() || path.back() - num == 1) {
            path.push_back(num);
            dfs(i + 1, i + 1);
            path.pop_back();
        }
    };

    dfs(0, 0);
    return ok;
}

bool splitString(string s) {
    int n = s.size();

    auto dfs = [&](this auto&& dfs, int start, string prev) -> bool {
        if (start == n) {
            return true;
        }

        for (int j = start; j < n; j++) {
            string t = s.substr(start, j - start + 1);
            // 及时剪枝
            if (stoll(t) > pow(10, 11)) break;
            if (stoll(prev) == stoll(t) + 1 && dfs(j + 1, t)) {
                return true;
            }
        }

        return false;
    };

    // 初始字符串只能截取到 [0, n - 1) 保证至少两个字符串
    for (int i = 0; i < n - 1; i++) {
        string s1 = s.substr(0, i + 1);
        // 及时剪枝
        if (stoll(s1) > pow(10, 11)) return false;
        if (dfs(i + 1, s1)) {
            return true;
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
