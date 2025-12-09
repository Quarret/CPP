#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), num = 0, l = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            num += abs(s[r] - t[r]);

            while (num > maxCost) {
                num -= abs(s[l] - t[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
