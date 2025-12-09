#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumFlips(int n) {
    int len = __bit_width(n);
    string s;
    for (int i = 0; i < len; i++) {
        if (n >> i & 1) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    
    string s1 = s;
    reverse(s1.begin(), s1.end());

    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != s1[i]) {
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
