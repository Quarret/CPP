#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> removeInvalidParentheses(string s) {
    int n = s.size();

    vector<string> ans;
    string path;
    int maxx = 0;

    auto check = [&](string s) -> bool {
        int m = s.size(), sum = 0;
        for (char c : s) {
            if (c == '(') sum++;
            else if (c == ')') sum--;

            if (sum < 0) return false;
        }

        return sum == 0;
    };

    unordered_map<string, int> mp;
    auto dfs = [&](this auto&& dfs, int i, int left, int k) -> void {
        if (path.size() == k) {
            if (!mp[path] && check(path)) {
                mp[path] = 1;
                ans.push_back(path);
            }
            return;
        }

        if (i == n) {
            return;
        }

        dfs(i + 1, left, k);

        if (s[i] == '(') {
            if (left >= k / 2) return;

            path.push_back(s[i]);
            dfs(i + 1, left + 1, k);
            path.pop_back();
        }

        if (s[i] == ')') {
            path.push_back(s[i]);
            dfs(i + 1, left, k);
            path.pop_back();
        }

        path.push_back(s[i]);
        dfs(i + 1, left, k);
        path.pop_back();
    };

    
    for (int t = n; t >= 0; t--) {
        dfs(0, 0, t);
        if (ans.size()) {
            break;
        }
    }

    return ans;
}

// 提前计算要删除的左右括号个数
vector<string> removeInvalidParentheses(string s) {
    int l = 0, r = 0, n = s.size();
    for (char c : s) {
        if (c == '(') l++;
        else if (c == ')') {
            if (l == 0) {
                r++;
            } else l--;
        }
    }
    
    unordered_set<string> st;
    string path;
    // cnt 为当前左剪右
    auto dfs = [&](this auto&& dfs, int i, int cnt, int l, int r) -> void {
        if (i == n) {
            if (!cnt) st.insert(path);
            return;
        }

        if (s[i] == '(') {
            // 不删
            path.push_back(s[i]);
            dfs(i + 1, cnt + 1, l, r);
            path.pop_back();    

            // 删
            if (l > 0) {
                dfs(i + 1, cnt, l - 1, r);
            }
        }

        if (s[i] == ')') {
            if (cnt > 0) {
                path.push_back(s[i]);
                dfs(i + 1, cnt - 1, l, r);
                path.pop_back();    
            }

            if (r > 0) {
                dfs(i + 1, cnt, l, r - 1);
            }
        }

        path.push_back(s[i]);
        dfs(i + 1, cnt, l, r);
        path.pop_back();
    };

    dfs(0, 0, l, r);
    vector<string> ans(st.begin(), st.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
