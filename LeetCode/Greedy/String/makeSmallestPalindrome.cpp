#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string makeSmallestPalindrome(string s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            char c = min(s[i], s[j]);
            s[i] = c;
            s[j] = c;
        }
        i++;
        j--;
    }
    
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
