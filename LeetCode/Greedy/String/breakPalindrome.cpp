#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    if (n == 1) {
        return "";
    }
    
    for (int i = 0; i < n / 2; i++) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }

    palindrome.back() = 'b';
    return palindrome;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
