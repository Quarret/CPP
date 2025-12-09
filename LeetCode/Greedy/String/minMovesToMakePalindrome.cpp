#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// s 很小, 可以暴力模拟
int minMovesToMakePalindrome(string s) {
    int n = s.size();
    int i = 0, j = n - 1;

    int ans = 0;
    while (i <= j) {
        int ok = 0;
        for (int k = j; k > i; k--) {
            if (s[i] == s[k]) {
                ok = 1;
                for (int t = k; t < j; t++) {
                    swap(s[t], s[t + 1]);
                    ans++;
                }
                break;
            }
        }
        if (!ok) {
            ans += n / 2 - i;
        }
        i++;
        if (ok) j--;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
