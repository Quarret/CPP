#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkOnesSegment(string s) {
    int n = s.size(), i = 0;
    for (; i < n; i++) {
        if (s[i] == '0') break;
    }

    for (; i < n; i++) {
        if (s[i] == '1') return false;
    }
    return true;
}

bool checkOnesSegment(string s) {
    return s.find("01") == s.npos;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}