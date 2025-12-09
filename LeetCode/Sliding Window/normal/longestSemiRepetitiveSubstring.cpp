#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestSemiRepetitiveSubstring(string s) {
    int n = s.size(), l = 0, num = 0, ans = 1;
    
    for (int r = 1; r < n; r++) {   
        if (s[r] == s[r - 1]) num++;

        while (num > 2) {
            if (s[l] == s[l + 1]) num--;
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
