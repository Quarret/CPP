#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int punishmentNumber(int n) {
    int ans = 0;

    for (int x = 1; x <= n; x++) {
        bool ok = false;
        string s = to_string(x * x);
        int m = s.size();
        vector<string> path;

        auto dfs = [&](this auto&& dfs, int i, int start) -> void {
            if (i == m) {
                int sum = 0;
                for (string t : path) {
                    sum += stoi(t);
                }
                if (sum == x) {
                    ok = true;
                }
                return;
            }

            if (i < n - 1) {
                dfs(i + 1, start);
            }

            string s1 = s.substr(start, i - start + 1);
            path.push_back(s1);
            dfs(i + 1, i + 1);
            path.pop_back();   
        };

        dfs(0, 0);
        if (ok) {
            ans += x * x;
        }
    }

    return ans;
}

// 预处理
int PRE_SUM[1001];

int init = []() {
    for (int x = 1; x <= 1000; x++) {
        bool ok = false;
        string s = to_string(x * x);
        int n = s.size();
        vector<string> path;

        auto dfs = [&](this auto&& dfs, int i, int start) -> void {
            if (i == n) {
                int sum = 0;
                for (string t : path) {
                    sum += stoi(t);
                }
                if (sum == x) {
                    ok = true;
                }
                return;
            }

            if (i < n - 1) {
                dfs(i + 1, start);
            }

            string s1 = s.substr(start, i - start + 1);
            path.push_back(s1);
            dfs(i + 1, i + 1);
            path.pop_back();   
        };

        dfs(0, 0);
        PRE_SUM[x] = PRE_SUM[x - 1] + (ok ? x * x : 0);
    }
    return 0;
}();

class Solution {
public:
    int punishmentNumber(int n) {
        return PRE_SUM[n];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
