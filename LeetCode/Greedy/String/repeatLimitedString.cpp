#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
    int cnt[26]{};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    
    string ans = "";
    for (int i = 25; i >= 0; i--) {
        if (!cnt[i]) continue;
        while (cnt[i]) {
            char ch = i + 'a';
            int c = min(cnt[i], repeatLimit);
            cnt[i] -= c;
            ans += string(c, ch);

            if (cnt[i] && c == repeatLimit) {
                int j = i - 1;
                while (j >= 0 && !cnt[j]) {
                    j--;
                }

                if (j == -1) return ans;
                ans += j + 'a';
                cnt[j]--;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
