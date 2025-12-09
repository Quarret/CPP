#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxOperations(string s) {
    int n = s.size(), pre = 0, ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i > 0 && s[i - 1] == '1') {
                ans += pre;
            }
        } else {
            pre++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
