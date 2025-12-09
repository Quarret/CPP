#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> letterCasePermutation(string s) {
    int n = s.size();
    string path(n, ' ');
    vector<string> ans;
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            path[i] = s[i];
            dfs(i + 1);
        } else {
            path[i] = tolower(s[i]);
            dfs(i + 1);

            path[i] = toupper(s[i]);
            dfs(i + 1);
        }
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
