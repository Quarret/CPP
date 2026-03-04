#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char, int> mp;
    
    int ans = 0;
    for (int r = 0, l = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp[s[r]] == 2) {
            mp[s[l]]--;
            l++;
        }
        ans = max(r - l + 1, ans);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
