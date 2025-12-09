#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> letterCombinations(string digits) {
    unordered_map<char, string> mp;
    mp['1'] = "";
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    int n = digits.size();
    string path(n, ' ');
    vector<string> ans;

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        string t = mp[digits[i]];
        for (char c : t) {
            path[i] = c;
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
