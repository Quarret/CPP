#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int balancedString(string s) {
    int n = s.size(), l = 0, num = 0, ans = 1e9, k = 0;
    
    vector<int> cnt(4, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Q') cnt[0]++;
        if (s[i] == 'W') cnt[1]++;
        if (s[i] == 'E') cnt[2]++;
        if (s[i] == 'R') cnt[3]++;
    }

    unordered_map<char, int> mp;
    unordered_map<char, int> mp1;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] - n / 4 > 0) {
            k += cnt[i] - n / 4;
            if (i == 0) mp['Q'] += 1;
            else if (i == 1) mp['W'] += 1;
            else if (i == 2) mp['E'] += 1;
            else if (i == 3) mp['R'] += 1;
        }
    }

    cout << n << '\n';
    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';
    cout << cnt[2] << '\n';
    cout << cnt[3] << '\n';

    if (k == 0) return 0;

    for (int r = 0; r < n; r++) {
        num += mp[s[r]];
        mp1[s[r]] += mp[s[r]] > 0;
        
        

        if (num < k) continue;

        for (auto it : mp) {
            if (it.second > 0 && it.second == mp1[it.first]) {
                
            }
        }

        while (num > k) {
            num -= mp[s[l]];
            l++;
        }

        ans = min(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    balancedString("WWWEQRQEWWQQQWQQQWEWEEWRRRRRWWQE");
    return 0;
}
