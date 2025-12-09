#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int canBeTypedWords(string text, string brokenLetters) {
    unordered_map<char, int> mp;
    for (char c : brokenLetters) {
        mp[c] = 1;
    }

    int ok = 1, ans = 0;
    for (char c : text) {
        if (mp[c]) ok = 0;
        if (c == ' ') {
            ans += ok;
            ok = 1;
        }
    }

    return ans + ok;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
