#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<string> path, ans;
    
    auto dfs = [&](this auto&& dfs, int i, int start) -> void {
        if (i == n) {
            if (path.size() == 4) {
                string tmp = "";
                for (int i = 0; i < 4; i++) {
                    tmp += path[i] + (i != 3 ? "." : "");
                }
                ans.push_back(tmp);
            }
            return;
        }

        if (i < n - 1) {
            dfs(i + 1, start);
        }

        string t = s.substr(start, i - start + 1);
        if ((t[0] == '0' && t.size() != 1) || t.size() >= 4 || stoi(t) > 255) return;
        
        path.push_back(t);
        dfs(i + 1, i + 1);
        path.pop_back();
    };

    dfs(0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
