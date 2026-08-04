#include <bits/stdc++.h>
using ll = long long;
using namespace std;


bool rotateString(string s, string goal) {
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        string res = s.substr(i, n - i) + s.substr(0, i);
        if (res == goal) return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}