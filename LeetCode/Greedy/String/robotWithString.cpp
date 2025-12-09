#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string robotWithString(string s) {
    string t = "", ans = "";
    
    int n = s.size();
    vector<char> suf(n + 1, 'z');
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i + 1], s[i]);
    }

    vector<int> st;
    for (int i = 0; i < n; i++) {
        st.push_back(s[i]);
        while (!st.empty() && st.back() <= suf[i + 1]) {
            ans += st.back();
            st.pop_back();
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
