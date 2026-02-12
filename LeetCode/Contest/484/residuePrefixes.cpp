#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int residuePrefixes(string s) {
    int n = s.size();
    unordered_set<char> st;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        st.insert(c);
        if (st.size() == (i + 1) % 3) {
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}