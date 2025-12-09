#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string removeOuterParentheses(string s) {
    int n = s.size(), cnt = 0;
    string ans;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cnt++;
            if (cnt > 1) ans.push_back('(');
        } else {
            if (cnt > 1) ans.push_back(')');
            cnt--;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
