#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string maximumXor(string s, string t) {
    int n = s.size();
    int cnt0 = 0, cnt1 = 0;
    for (char c : t) {
        ((c == '0') ? cnt0 : cnt1) += 1;
    }

    string ans = s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (cnt1) {
                ans[i] = '1';
                cnt1--;
            } else {
                ans[i] = '0';
                cnt0--;
            }
        } else {
            if (cnt0) {
                ans[i] = '1';
                cnt0--;
            } else {
                cnt1--;
                ans[i] = '0';
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}