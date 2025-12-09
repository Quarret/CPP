#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string largestPalindromic(string num) {
    int cnt[10]{};
    for (char c : num) {
        cnt[c - '0']++;
    }
    
    string s = "";
    int mid = -1;
    for (int i = 9; i >= 0; i--) {
        s += string(cnt[i] / 2, i + '0');
        if (cnt[i] % 2) {
            mid = max(mid, i);
        }
    }

    string ans = "";
    if (s[0] == '0') {
        if (mid != -1) {
            ans.push_back(mid + '0');
        } else {
            ans.push_back('0');
        } 
    } else {
        string s1 = s;
        ranges::reverse(s1);
        if (mid != -1) s.push_back(mid + '0');
        ans = s + s1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
