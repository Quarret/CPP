#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string alienOrder(vector<string>& words) {
    int n = words.size(), ok = 0;

    if (n == 1) return words[0];

    unordered_map<char, vector<char>> g;
    unordered_set<char> st;
    unordered_map<char, int> in_deg;
    for (int i = 0; i < n - 1; i++) {
        string s1 = words[i], s2 = words[i + 1];

        int j = 0;
        for (j = 0; j < min(s1.size(), s2.size()); j++) {
            char c1 = s1[j], c2 = s2[j];
            if (c1 != c2) {
                g[c1].push_back(c2);
                in_deg[c2]++;
                break;
            }
        }
        if (j == s2.size() && s1.size() != s2.size()) ok = 1;

        for (char c : s1) st.insert(c);
        for (char c : s2) st.insert(c);
    }

    queue<char> q;
    for (auto c : st) {
        if (!in_deg[c]) q.push(c);
    }
    
    string ans;
    while (!q.empty()) {
        char u = q.front();
        q.pop();
        ans += u;

        for (char v : g[u]) {
            in_deg[v]--;
            if (!in_deg[v]) q.push(v);
        }
    }

    if (ans.size() != st.size() || ok) return "";
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
