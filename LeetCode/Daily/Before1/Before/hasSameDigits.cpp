#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool hasSameDigits(string s) {
    while (s.size() > 2) {
        int n = s.size();
        string tmp = "";
        for (int i = 0; i < n - 1; i++) {
            int x = s[i] - '0', y = s[i + 1] - '0';
            tmp += ((x + y) % 10) + '0';
        }

        s = tmp;
    }
    
    return s[0] == s[1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
