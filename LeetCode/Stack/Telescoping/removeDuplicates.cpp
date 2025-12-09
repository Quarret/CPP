#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string removeDuplicates(string s) {
    int n = s.size();
    stack<char> st;

    for (int i = n - 1; i >= 0; i--) {
        if (!st.empty() && s[i] == st.top()) st.pop();
        else st.push(s[i]);
    }

    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
