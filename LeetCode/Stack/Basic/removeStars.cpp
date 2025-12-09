#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string removeStars(string s) {
    int n = s.size();
    stack<char> st;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') st.push(s[i]);
        else st.pop();
    }

    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
