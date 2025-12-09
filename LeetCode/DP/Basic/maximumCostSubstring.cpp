#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int n = s.size(), m = chars.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < m; i++) mp[chars[i]] = vals[i];
    vector<int> f(n + 1);
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int val = mp.find(c) != mp.end() ? mp[c] : c - 'a' + 1;
        
        f[i + 1] = max(f[i], 0) + val;
    }

    return *max_element(f.begin(), f.end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
