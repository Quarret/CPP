#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> validStrings(int n) {
    vector<string> ans;
    string path(n, ' ');
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        path[i] = '1';
        dfs(i + 1);

        if (i == 0 || (i > 0 && path[i - 1] != '0')) {
            path[i] = '0';
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
