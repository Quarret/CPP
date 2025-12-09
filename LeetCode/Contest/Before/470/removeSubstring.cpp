#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string removeSubstring(string s, int k) {
    string del = "";
    for (int i = 0; i < 2 * k; i++) {
        if (i < k) del += '(';
        else del += ')';
    };
    
    int pos = 0;
    while (s.find(del, pos) != -1) {
        int pos = s.find(del);
        s.erase(pos, 2 * k);
        if (pos >= s.size()) break;
        pos = s[pos] == '(' ? pos : 0;
    }

    return s;
}

string removeSubstring(string s, int k) {
    // 数组模拟栈
    vector<pair<char, int>> st;
    for (char c : s) {
        if (!st.empty() && st.back().first == c) {
            st.back().second++;
        } else {
            st.emplace_back(c, 1);
        }

        // ')' 恰好k个时
        if (c == ')' && st.size() > 1 && st.back().second == k && st[st.size() - 2].second >= k) {
            st.pop_back();
            st.back().second -= k;
            if (!st.back().second) {
                st.pop_back();
            }
        }
    }

    string ans = "";
    for (auto p : st) {
        // string(cnt, char) = char * cnt
        ans += string(p.second, p.first);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
