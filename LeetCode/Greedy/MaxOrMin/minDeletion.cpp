#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minDeletion(string s, int k) {
    vector<int> cnt(26, 0);
    int num = 0;
    for (char c : s) {
        if (!cnt[c - 'a']) num++;
        cnt[c - 'a']++;
    }
    
    sort(cnt.begin(), cnt.end());
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (num <= k) return ans;
        ans += cnt[i];
        num -= cnt[i] > 0;
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
