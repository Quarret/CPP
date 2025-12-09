#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool canConstruct(string s, int k) {
    int n = s.size();
    if (k > n) return false;
    
    int cnt[26]{};
    for (char c : s) {
        cnt[c - 'a']++;
    }

    int ans = 0, res = 0;
    for (int c : cnt) {
        if (c % 2) res++;
        if (c) ans = 1;
    }
    ans = max(ans, res);
    return k >= ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
