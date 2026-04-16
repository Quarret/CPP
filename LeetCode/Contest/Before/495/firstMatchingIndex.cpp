#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int firstMatchingIndex(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (n - 1 - i >= 0 && s[i] == s[n - 1 - i]) return i;
    }
    
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}