#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool doesAliceWin(string s) {
    for (char c : s) {
        if (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u') {
            return true;
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
