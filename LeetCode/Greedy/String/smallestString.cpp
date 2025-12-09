#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string smallestString(string s) {
    int ok = 0, ok1 = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            if (!ok) {
                continue;
            } else {
                ok1 = 1;
            } 
        } else if (!ok1) {
            ok = 1;
            s[i]--;
        }
    }

    if (!ok) s.back() = 'z';
    return s;
}

string smallestString(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] > 'a') {
            for (; i < n && s[i] > 'a'; i++) {
                s[i]--;
            }
            return s;
        }
    }

    s.back() = 'z';
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
