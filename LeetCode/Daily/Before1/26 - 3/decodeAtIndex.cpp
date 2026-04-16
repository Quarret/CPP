#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 只维护恰好超过 k 的字符串
string decodeAtIndex(string s, int k) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            ans.push_back(s[i]);
        } else {
            string t = ans;
            for (int j = 0; j < s[i] - '1'; j++) {
                ans += t;
            }
        }

        if (ans.size() >= k) return string(1, ans[k - 1]);
    }

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}