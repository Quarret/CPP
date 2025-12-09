#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string removeDigit(string number, char digit) {
    int n = number.size();
    string ans(n - 1, '0');
    
    for (int i = 0; i < n; i++) {
        if (number[i] != digit) continue;
        string s = number;
        s.erase(i, 1);
        ans = max(ans, s);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
