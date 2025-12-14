#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        mp[c].push_back(i - mp[c].size());
    }

    int ans = 0;
    for (auto &[_, pos] : mp) {
        for (int r = 0, l = 0; r < pos.size(); r++) {
            while (pos[r] - pos[l] > k) {
                l++;
            }
            ans = max(ans, min(r - l + 1 + k, n));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
