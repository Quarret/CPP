#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countPalindromicSubsequence(string s) {
    int n = s.size();
    int pre[26]{}, suf[26]{}, cnt[26]{};

    for (int i = 1; i < n; i++) {
        suf[s[i] - 'a']++;
    }
    pre[s[0] - 'a']++;

    for (int mid = 1; mid < n - 1; mid++) {
        suf[s[mid] - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (pre[i] && suf[i]) {
                cnt[s[mid] - 'a'] |= 1 << i;
            }
        }

        pre[s[mid] - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += __builtin_popcount(cnt[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
