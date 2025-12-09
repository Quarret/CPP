#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> cnt;
    
    for (char c : s) {
        cnt[c]++;
    }

    int ans = 0, ok = 0;
    for (auto [_, c] : cnt) {
        ans += c - c % 2;
        if (c % 2) ok = 1;
    }

    return ans + ok;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
