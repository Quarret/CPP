#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countBinarySubstrings(string s) {
    int n = s.size();
    int pre = 0, cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cur++;
        if (i == n - 1 || s[i] !=s[i + 1]) {
            ans += min(pre, cur);
            pre = cur;
            cur = 0;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}