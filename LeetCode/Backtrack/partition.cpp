#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> ans;
    vector<string> path;
    
    auto check = [&](string s1) -> bool {
        int l = 0, r = s1.size() - 1;
        while (l < r) {
            if (s1[l] == s1[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    };

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        for (int j = i; j < n; j++) {
            string t = s.substr(i, j - i + 1);
            if (check(t)) {
                path.push_back(t);
                dfs(j + 1);
                path.pop_back();
            }
        }
    };

    dfs(0);
    return ans;
}

// 从输入视角
vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> ans;
    vector<string> path;
    
    auto check = [&](string s1) -> bool {
        int l = 0, r = s1.size() - 1;
        while (l < r) {
            if (s1[l] == s1[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    };

    // start 为回文字符串开始位置
    auto dfs = [&](this auto&& dfs, int i, int start) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        // 最后的位置 i == n - 1 必须分割
        if (i < n - 1) {// i 不分割
            dfs(i + 1, start);
        }

        // i 分割
        string t = s.substr(start, i - start + 1);
        if (check(t)) {
            path.push_back(t);
            dfs(i + 1, i + 1); // start 现在为 i + 1
            path.pop_back();
        }
    };

    dfs(0, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
