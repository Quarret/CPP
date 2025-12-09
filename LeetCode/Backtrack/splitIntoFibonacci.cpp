#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


vector<int> splitIntoFibonacci(string num) {
    int n = num.size();
    vector<int> path, ans;

    auto check = [&](string s) -> bool {
        for (char c : s) {
            if (c != '0') {
                return false;
            }
        }

        return true;
    };
    
    auto dfs = [&](this auto&& dfs, int i) -> bool {
        if (i == n) {
            ans = path;
            return true;
        }

        for (int j = i; j < n; j++) {
            string t = num.substr(i, j - i + 1);
            if (t[0] == '0' && !check(t)) continue;

            if (t.size() >= 16) break;
            long long num1 = path[path.size() - 2], num2 = path[path.size() - 1];
            
            path.push_back(stoll(t));

            if (num1 + num2 == stoll(t) && dfs(j + 1)) {
                return true;
            }
            
            path.pop_back();
        }

        return false;
    };

    for (int i = 0; i < n - 2; i++) {
        string s1 = num.substr(0, i + 1);
        if (s1.size() >= 16) {
            return {};
        }

        if (s1[0] == '0' && !check(s1)) continue;

        path.push_back(stoll(s1));

        for (int j = i + 1; j < n - 1; j++) {
            string s2 = num.substr(i + 1, j - i);

            if (s2[0] == '0' && !check(s2)) continue;

            if (s2.size() >= 16) break;
            path.push_back(stoll(s2));

            if (dfs(j + 1)) {
                return ans;
            }

            path.pop_back();
        }
        path.pop_back();
    }

    return {};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
