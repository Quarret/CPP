#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfSubstrings(string s, int k) {
        int n = s.size(), l = 0, ans = 0, num = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;

            while (mp[s[r]] == k) {
                mp[s[l]]--;
                l++;
            }

            ans += l;
        }

        return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    numberOfSubstrings("abacb", 2);
    return 0;
}
