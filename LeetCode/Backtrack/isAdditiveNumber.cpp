#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool isAdditiveNumber(string num) {
    int n = num.size();

    auto dfs = [&](this auto&& dfs, int i, string pre1, string pre2) -> bool {
        if (i == n) {
            return true;
        }

        if (pre1[0] == '0' && stoll(pre1) != 0) return false;
        if (pre2[0] == '0' && stoll(pre2) != 0) return false;
        
        for (int j = i; j < n; j++) {
            string t = num.substr(i, j - i + 1);
            if (t[0] == '0' && stoll(t) != 0) continue;
            if (stoll(t) > pow(10, 16)) break;
            if (stoll(pre1) + stoll(pre2) == stoll(t) && dfs(j + 1, pre2, t)) {
                return true;
            }
        }

        return false;
    };
    
    for (int i = 0; i < n - 2; i++) {
        string s1 = num.substr(0, i + 1);
        if (stoll(s1) > pow(10, 16)) return false;
        for (int j = i + 1; j < n - 1; j++) {
            string s2 = num.substr(i + 1, j - i);
            if (stoll(s2) > pow(10, 16)) break;
            if (dfs(j + 1, s1, s2)) {
                return true;
            }
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
