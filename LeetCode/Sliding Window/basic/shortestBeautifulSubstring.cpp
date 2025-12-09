#include <bits/stdc++.h>
using ll = long long;
using namespace std;


string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), num = 0, l = 0, ans = 1e9;
        string substr = "";

        for (int r = 0; r < n; r++) {
            num += s[r] == '1';

            while (num > k || s[l] == '0') {
                num -= s[l] == '1';
                l++;
            }
            
            if (num < k) continue;

            if (r - l + 1 < ans) {
                ans = r - l + 1;
                substr = s.substr(l, r - l + 1);
            } else if (r - l + 1 == ans && substr < s.substr(l, r - l + 1)) {
                substr = s.substr(l, r - l + 1);
            }
        }

        return substr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
