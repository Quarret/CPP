#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int balancedStringSplit(string s) {
    int n = s.size();
    int cntL = 0, cntR = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        (s[i] == 'R' ? cntR : cntL) += 1;
        if (cntR == cntL) {
            ans++;
            cntR = 0;
            cntL = 0;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
