#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool backspaceCompare(string s, string t) {
    int n = s.size(), m = t.size();
    stack<char> st1, st2;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != '#') st1.push(s[i]);
        else if (!st1.empty()) st1.pop();
    }

    for (int i = 0; i < m; i++) {
        if (t[i] != '#') st2.push(t[i]);
        else if (!st2.empty()) st2.pop();
    }

    if (st1.size() != st2.size()) return 0;
    while (!st1.empty()) {
        if (st1.top() != st2.top()) return 0;
        st1.pop();
        st2.pop();
    }

    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
