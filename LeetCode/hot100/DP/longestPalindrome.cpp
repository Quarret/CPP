#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 中心扩散法 O(1) 判断回文串
string longestPalindrome(string s) {
    int n = s.size();
    int ans_l = 0, ans_r = 0;
    
    // 奇数回文串
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        // s[l + 1, r - 1] 为回文串
        if (r - l - 1 > ans_r - ans_l) {
            ans_l = l + 1;
            ans_r = r; // 左闭右开
        }
    }

    // 偶数回文串
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        if (r - l - 1 > ans_r - ans_l) {
            ans_l = l + 1;
            ans_r = r;
        }
    }

    return s.substr(ans_l, ans_r - ans_l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}