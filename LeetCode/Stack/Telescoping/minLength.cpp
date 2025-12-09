#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minLength(string s) {
    int n = s.size();
    stack<char> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty() && st.top() == 'A' && s[i] == 'B') st.pop();
        else if (!st.empty() && st.top() == 'C' && s[i] == 'D') st.pop();
        else st.push(s[i]);
    }

    return st.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
