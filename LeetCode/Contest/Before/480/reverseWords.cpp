#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string reverseWords(string s) {
    s.push_back(' ');
    
    int cnt = -1;
    int cnt1 = 0;
    string s1;
    vector<string> ans;
    for (char c : s) {
        if (c != ' ') s1.push_back(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cnt1++;
        } else if (c == ' ') {
            if (cnt1 == cnt) {
                ranges::reverse(s1);
            }
            ans.push_back(s1);
            s1.clear();

            if (cnt == -1) {
                cnt = cnt1;
            }
            cnt1 = 0;
        }
    }

    string res = "";
    for (string s1 : ans) {
        s1.push_back(' ');
        res += s1;
    }
    res.pop_back();
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
