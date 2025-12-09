#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string removeKdigits(string num, int k) {
    int n = num.size();
    if (n <= k) return "0";
    
    vector<char> st;
    for (char c : num) {
        while (st.size() && c < st.back() && k) {
            k--;
            st.pop_back();
        }
        st.push_back(c);
    }

    while (k) {
        st.pop_back();
        k--;
    }

    string ans = "";
    int ok = 0;
    for (char c : st) {
        if (c == '0' && !ok) continue;
        ok = 1;
        ans += c; 
    }
    return ans == "" ? "0" : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
