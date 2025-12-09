#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string smallestPalindrome(string s) {
    int cnt[26]{};
    for (char c : s) {
        cnt[c - 'a']++; 
    }
    
    char mid = ' ';
    string half;
    for (int i = 0; i < 26; i++) {
        char ch = i + 'a';
        if (cnt[i] % 2) {
            mid = ch;
        }
        half += string(cnt[i] / 2, ch);
    }

    string otherHalf = half;
    ranges::reverse(otherHalf);
    return mid == ' ' ? half + otherHalf : half + mid + otherHalf;
}

string smallestPalindrome(string s) {
    int n = s.size();
    string t = s.substr(0, n / 2);
    ranges::sort(t);

    string ans = t;
    if (n % 2) {
        ans += s[n / 2];
    }

    ranges::reverse(t);
    return ans + t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
