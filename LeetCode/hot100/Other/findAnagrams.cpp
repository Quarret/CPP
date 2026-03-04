#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int n = s.size(), m = p.size();
    unordered_map<int, int> mp1, mp2;
    for (auto &c : p) {
        mp2[c - 'a']++;
    }

    vector<int> ans;
    for (int r = 0, l = 0; r < n; r++) {
        mp1[s[r] - 'a']++;

        if (r < m - 1) continue;
        int ok = 1;
        for (int i = 0; i < 26; i++) {
            if (mp1[i] != mp2[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) ans.push_back(l);        
        mp1[s[l] - 'a']--;
        l++; 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
