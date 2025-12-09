#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    
    for (int i = 0; i < n; i++) {
        if (!st.empty() && s[i] == 'c' && st.top() == 'b') {
            st.pop();
            if (!st.empty() && st.top() == 'a') st.pop();
            else {
                st.push('b');
                st.push('c');
            }
        } else st.push(s[i]);  
    }

    return st.size() == 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
