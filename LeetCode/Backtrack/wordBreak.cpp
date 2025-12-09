#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_map<string, int> mp;
    for (string s : wordDict) {
        mp[s] = 1;
    }
    
    vector<string> path, ans;
    auto dfs = [&](this auto&& dfs, int i, int start) -> void {
        if (i == n) {
            string tmp;
            for (string t : path) {
                tmp += t + " ";
            }
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }

        if (i < n - 1) {
            dfs(i + 1, start);
        }

        string t = s.substr(start, i - start + 1);
        if (!mp[t]) return;
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
