#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int longestPalindrome(vector<string>& words) {
    int n = words.size();
    unordered_map<string, int> cnt;
    unordered_map<string, int> vis;
    for (string s : words) {
        cnt[s]++;
    }    

    int ans = 0, ok = 0;
    for (string s : words) {
        if (vis[s]) continue;
        string s1 = s;
        ranges::reverse(s1);
        vis[s] = vis[s1] = 1;

        if (s[0] == s[1]) {
            ans += cnt[s] / 2 * 4;
            if (cnt[s] % 2) ok = 1;
            continue;
        }

        ans += min(cnt[s], cnt[s1]) * 4;
    }

    return ans + ok * 2;
}

// 注意只有两个字符
int longestPalindrome(vector<string>& words) {
    int cnt[26][26]{};
    for (auto &w : words) {
        cnt[w[0] - 'a'][w[1] - 'a']++;
    }
    
    int ans = 0, odd = 0;
    for (int i = 0; i < 26; i++) {
        int c = cnt[i][i];
        ans += c - c % 2;
        odd |= c % 2;

        for (int j = i + 1; j < 26; j++) {
            ans += min(cnt[i][j], cnt[j][i]) * 2;
        }
    }

    return (ans + odd) * 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
