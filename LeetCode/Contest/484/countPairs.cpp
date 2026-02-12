#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countPairs(vector<string>& words) {
    using ll = long long;
    int n = words.size(), m = words[0].size();

    ll ans = 0;
    unordered_map<string, ll> cnt;
    for (int i = 0; i < n; i++) {
        string s = words[i];
        for (int c = 0; c < 26; c++) {
            for (int j = 0; j < m; j++) {
                s[j] = ((s[j] - 'a') + 1) % 26 + 'a';
            }
            cout << s << '\n';
            ans += cnt[s];
        }
        cnt[words[i]]++;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}