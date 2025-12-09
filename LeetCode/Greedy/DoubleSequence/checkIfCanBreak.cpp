#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool checkIfCanBreak(string s1, string s2) {
    string min_s1 = s1;        
    string min_s2 = s2;        

    ranges::sort(min_s1);
    ranges::sort(min_s2);

    int n = s1.size(), ok = 1;
    for (int i = 0; i < n; i++) {
        if (min_s1[i] > min_s2[i]) {
            ok = 0;
        }
    }

    if (ok) {
        return true;
    }

    ok = 1;
    for (int i = 0; i < n; i++) {
        if (min_s1[i] < min_s2[i]) {
            ok = 0;
        }
    }

    if (ok) {
        return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
