#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool validPalindrome(string s) {
    auto check = [&](int i, int j) -> bool {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    };

    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return check(i + 1, j) || check(i, j - 1);
        }
        i++;
        j--;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
