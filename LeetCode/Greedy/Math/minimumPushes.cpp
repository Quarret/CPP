#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumPushes(string word) {
    vector<int> cnt(26, 0);
    for (char c : word) {
        cnt[c - 'a']++;
    }
    
    int ans = 0;
    ranges::sort(cnt, greater());
    for (int i = 0; i < 26; i++) {
        ans += cnt[i] * (i / 8 + 1);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
