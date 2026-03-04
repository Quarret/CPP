#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    unordered_map<int, int> mp1, mp2;
    for (auto &c : t) {
        mp2[c - 'A']++;
    }
    
    auto check = [&]() -> bool {
        for (int i = 0; i < 26; i++) {
            if (mp1[i] < mp2[i]) return false;
        }

        return true;
    };

    int left = 0, right = 0, mn = 1e9;
    for (int r = 0, l = 0; r < n; r++) {
        mp1[s[r] - 'A']++;

        while (check()) {
            if (r - l + 1 < mn) {
                mn = r - l + 1;
                right = r;
                left = l;
            }

            mp1[s[l] - 'A']--;
            l++;
        }
    }

    return s.substr(left, right - left + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
